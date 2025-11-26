#include <iostream>
#include <cuda_runtime.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>

#define CHECK_CUDA_ERROR(call) do { \
    cudaError_t err = call; \
    if (err != cudaSuccess) { \
        std::cerr << "CUDA error at " << __FILE__ << ":" << __LINE__ \
                  << ": " << cudaGetErrorString(err) << std::endl; \
        exit(EXIT_FAILURE); \
    } \
} while(0)

const size_t DATA_SIZE = 1024 * 1024; // 1M elements
const char* IPC_HANDLE_FILE = "ipc_handle.txt";
const float TOLERANCE = 1e-6f;

int main() {
    std::cout << "Consumer process started..." << std::endl;
    
    // 1. 读取IPC句柄
    cudaIpcMemHandle_t ipc_handle;
    std::ifstream handle_file(IPC_HANDLE_FILE, std::ios::binary);
    if (!handle_file) {
        std::cerr << "Failed to open IPC handle file for reading" << std::endl;
        return EXIT_FAILURE;
    }
    
    handle_file.read(reinterpret_cast<char*>(&ipc_handle), sizeof(ipc_handle));
    handle_file.close();
    std::cout << "IPC handle read from " << IPC_HANDLE_FILE << std::endl;
    
    // 2. 打开IPC内存
    void* d_data_void;
    CHECK_CUDA_ERROR(cudaIpcOpenMemHandle(&d_data_void, ipc_handle, cudaIpcMemLazyEnablePeerAccess));
    float* d_data = static_cast<float*>(d_data_void);
    std::cout << "IPC memory handle opened successfully" << std::endl;
    
    // 3. 准备主机内存用于读取数据
    std::vector<float> h_data(DATA_SIZE);
    
    // 4. 从GPU复制数据到主机
    CHECK_CUDA_ERROR(cudaMemcpy(h_data.data(), d_data, DATA_SIZE * sizeof(float), 
                                cudaMemcpyDeviceToHost));
    std::cout << "Data copied from GPU to host" << std::endl;
    
    // 5. 验证数据正确性
    bool data_valid = true;
    size_t error_count = 0;
    
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        float expected = static_cast<float>(i) * 0.001f;
        float diff = std::abs(h_data[i] - expected);
        if (diff > TOLERANCE) {
            data_valid = false;
            error_count++;
            if (error_count <= 10) { // 只打印前10个错误
                std::cerr << "Data mismatch at index " << i 
                         << ": expected " << expected 
                         << ", got " << h_data[i] 
                         << ", diff: " << diff << std::endl;
            }
        }
    }
    
    // 6. 输出验证结果
    if (data_valid) {
        std::cout << "✓ Data validation PASSED! All " << DATA_SIZE 
                  << " elements are correct." << std::endl;
        
        // 输出一些样本数据
        std::cout << "Sample data points:" << std::endl;
        for (size_t i = 0; i < 10; ++i) {
            std::cout << "  [" << i << "] = " << h_data[i] << std::endl;
        }
        std::cout << "  ... " << std::endl;
        for (size_t i = DATA_SIZE - 10; i < DATA_SIZE; ++i) {
            std::cout << "  [" << i << "] = " << h_data[i] << std::endl;
        }
    } else {
        std::cout << "✗ Data validation FAILED! " << error_count 
                  << " out of " << DATA_SIZE << " elements are incorrect." << std::endl;
    }
    
    // 7. 关闭IPC内存句柄
    CHECK_CUDA_ERROR(cudaIpcCloseMemHandle(d_data));
    std::cout << "IPC memory handle closed" << std::endl;
    
    std::cout << "Consumer process completed!" << std::endl;
    
    return data_valid ? EXIT_SUCCESS : EXIT_FAILURE;
}