#include <cstdio>
#include "matrix.h"

__global__ void BlockGEMM_V1(Matrix<float> A, Matrix<float> B, Matrix<float> C) {
    // 注意命名不要与前面的宏定义重名
    const int BLOCK_M = 16;// block的行数
    const int BLOCK_N = 16;// block的列数
    const int BLOCK_K = 16;

    // 沿着K维度循环加载一个block中对应的A和B的数据到共享内存
    float c = 0.0;
    for (int i = 0; i < A.cols / BLOCK_K; ++i) {
        // 每个block对应的全局内存中的A,B子块，即创建全局内存中A,B的view
        Matrix<float> ASub(A.data + blockIdx.y * BLOCK_M * A.strideOfRow + i * BLOCK_K, BLOCK_M, BLOCK_K, A.strideOfRow,
                           A.strideOfCol);
        Matrix<float> BSub(B.data + i * BLOCK_K * B.strideOfRow + blockIdx.x * BLOCK_N, BLOCK_K, BLOCK_N, B.strideOfRow,
                           B.strideOfCol);

        // 将Asub,BSub加载到共享内存
        // 注意：这里需要将一维线性逻辑索引转换为多维逻辑索引：startIndex->(startIndex/cols, startIndex%cols)
        __shared__ float A_Shared[BLOCK_M][BLOCK_K];
        __shared__ float B_Shared[BLOCK_K][BLOCK_N];

        int numberOfElementsPerThread = (BLOCK_K * BLOCK_M) / (blockDim.x * blockDim.y);// 每个线程需要读取多少数据
        int startIndex = numberOfElementsPerThread * (threadIdx.y * blockDim.x + threadIdx.x);// startIndex为每个线程读取的起始索引

        //搬运到shared memory
        for (int threadIndex = 0; threadIndex < numberOfElementsPerThread; ++threadIndex) {
            int logicalIndex = startIndex + threadIndex;
            A_Shared[logicalIndex / BLOCK_K][logicalIndex % BLOCK_K] = ASub(logicalIndex / BLOCK_K,
                                                                            logicalIndex % BLOCK_K);
            B_Shared[logicalIndex / BLOCK_N][logicalIndex % BLOCK_N] = BSub(logicalIndex / BLOCK_N,
                                                                            logicalIndex % BLOCK_N);
        }
        __syncthreads();

        // 每个thread计算A的一行和B的一列
        for (int k = 0; k < BLOCK_K; ++k) {
            c += A_Shared[threadIdx.y][k] * B_Shared[k][threadIdx.x];
        }
        __syncthreads();

    }

    // 将每个线程计算好的结果写回到C矩阵
    // CSub为每个线程对应的全局内存的C矩阵子块，创建C矩阵的view
    Matrix<float> CSub(C.data + (blockIdx.y * BLOCK_M * C.strideOfRow + blockIdx.x * BLOCK_N), BLOCK_M, BLOCK_N,
                       C.strideOfRow, C.strideOfCol);
    CSub(threadIdx.y, threadIdx.x) = c;

}
