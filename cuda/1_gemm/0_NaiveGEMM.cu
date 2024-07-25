#include <cstdio>
#include "matrix.h"
//tutorial: https://blog.csdn.net/qianqing13579/article/details/127359866
//code: https://github.com/qianqing13579/GEMM/blob/master/GEMM.cu
__global__ void NaiveGEMM(Matrix<float> A,Matrix<float> B,Matrix<float> C) {

    // 获取线程在网格内的索引
    int row = blockIdx.y * blockDim.y + threadIdx.y;// 行
    int col = blockIdx.x * blockDim.x + threadIdx.x;// 列

    // 每个线程计算矩阵C的一个元素
    if(row < C.rows && col < C.cols) {
        float c = 0;
        for (int i = 0; i < A.cols; ++i) {  //相当于一个线程，处理C中的一个元素，也就是A和B的一行/一列
            c += A(row,i) * B(i,col);// 使用A的第row行乘以B的第col列
        }
        C(row,col) = c;
    }
}



int main(int argc,char **argv)
{

    printf("GEMM_v1: NaiveGEMM\n");
    // 创建GPU A矩阵
    float *dataOfA_Device=nullptr;
    cudaMalloc((void **)&dataOfA_Device, A_Host.rows*A_Host.cols*sizeof(float));
    cudaMemcpy(dataOfA_Device, A_Host.data, A_Host.rows*A_Host.cols*sizeof(float), cudaMemcpyHostToDevice);
    Matrix<float> A_Device(dataOfA_Device,A_Host.rows,A_Host.cols,A_Host.cols,1);

    // 创建GPU B矩阵
    float *dataOfB_Device=nullptr;
    cudaMalloc((void **)&dataOfB_Device, B_Host.rows*B_Host.cols*sizeof(float));
    cudaMemcpy(dataOfB_Device, B_Host.data, B_Host.rows*B_Host.cols*sizeof(float), cudaMemcpyHostToDevice);
    Matrix<float> B_Device(dataOfB_Device,B_Host.rows,B_Host.cols,B_Host.cols,1);

    // 创建GPU C矩阵
    float *dataOfC_Device=nullptr;
    cudaMalloc((void **)&dataOfC_Device, A_Host.rows*B_Host.cols*sizeof(float));
    Matrix<float> C_Device(dataOfC_Device,A_Host.rows,B_Host.cols,B_Host.cols,1);
    return 0;
}