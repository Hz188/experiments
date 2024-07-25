/// MyCublas.cu

#include "MyCublas.cuh"
#include "CublasUtility.h"
#include <vector>

void MatrixMulVectorCublas(
        const double* matrix, const int row, const int col,
        const double* vector, double* result
)
{
    /* step 1: create cublas handle, bind a stream */
    cublasHandle_t cublasH = NULL;
    cudaStream_t stream = NULL;

    CUBLAS_CHECK(cublasCreate(&cublasH));

    CUDA_CHECK(cudaStreamCreateWithFlags(&stream, cudaStreamNonBlocking));
    CUBLAS_CHECK(cublasSetStream(cublasH, stream));

    /* step 2: copy data to device */
    double* dev_matrix = nullptr;
    double* dev_vector = nullptr;
    double* dev_result = nullptr;

    CUDA_CHECK(cudaMalloc(reinterpret_cast<void**>(&dev_matrix), sizeof(double) * row * col));
    CUDA_CHECK(cudaMalloc(reinterpret_cast<void**>(&dev_vector), sizeof(double) * col));
    CUDA_CHECK(cudaMalloc(reinterpret_cast<void**>(&dev_result), sizeof(double) * row));

    CUDA_CHECK(cudaMemcpyAsync(dev_matrix, matrix, sizeof(double) * row * col, cudaMemcpyHostToDevice,
                               stream));
    CUDA_CHECK(cudaMemcpyAsync(dev_vector, vector, sizeof(double) * col, cudaMemcpyHostToDevice,
                               stream));

    /* step 3: compute */
    cublasOperation_t transa = CUBLAS_OP_N;
    const int lda = row;
    const double alpha = 1.0;
    const double beta = 0.0;
    const int incx = 1;
    const int incy = 1;

    CUBLAS_CHECK(
            cublasDgemv(cublasH, transa, row, col, &alpha, dev_matrix, lda, dev_vector, incx, &beta, dev_result, incy));

    /* step 4: copy data to host */
    CUDA_CHECK(cudaMemcpyAsync(result, dev_result, sizeof(double) * row, cudaMemcpyDeviceToHost,
                               stream));

    CUDA_CHECK(cudaStreamSynchronize(stream));

    /* step 5: free resources */
    CUDA_CHECK(cudaFree(dev_matrix));
    CUDA_CHECK(cudaFree(dev_vector));
    CUDA_CHECK(cudaFree(dev_result));

    CUBLAS_CHECK(cublasDestroy(cublasH));
    CUDA_CHECK(cudaStreamDestroy(stream));
    CUDA_CHECK(cudaDeviceReset());
}

