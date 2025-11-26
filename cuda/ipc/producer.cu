#include <iostream>
#include <cuda_runtime.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

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

int main() {
    std::cout << "Producer process started..." << std::endl;
    
    // 1. 分配GPU内存
    float* d_data;
    CHECK_CUDA_ERROR(cudaMalloc(&d_data, DATA_SIZE * sizeof(float)));
    std::cout << "Allocated " << DATA_SIZE * sizeof(float) << " bytes on GPU" << std::endl;
    
    // 2. 准备测试数据
    std::vector<float> h_data(DATA_SIZE);
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        h_data[i] = static_cast<float>(i) * 0.001f;
    }
    
    // 3. 将数据复制到GPU
    CHECK_CUDA_ERROR(cudaMemcpy(d_data, h_data.data(), DATA_SIZE * sizeof(float), 
                                cudaMemcpyHostToDevice));
    std::cout << "Data copied to GPU memory" << std::endl;
    
    // 4. 获取IPC句柄
    cudaIpcMemHandle_t ipc_handle;
    CHECK_CUDA_ERROR(cudaIpcGetMemHandle(&ipc_handle, d_data));
    std::cout << "IPC handle generated" << std::endl;
    
    // 5. 将IPC句柄写入文件
    std::ofstream handle_file(IPC_HANDLE_FILE, std::ios::binary);
    if (!handle_file) {
        std::cerr << "Failed to open IPC handle file for writing" << std::endl;
        cudaFree(d_data);
        return EXIT_FAILURE;
    }
    
    handle_file.write(reinterpret_cast<const char*>(&ipc_handle), sizeof(ipc_handle));
    handle_file.close();
    std::cout << "IPC handle written to " << IPC_HANDLE_FILE << std::endl;
    
    // 6. 等待消费者进程准备就绪
    std::cout << "Waiting for consumer process..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // 7. 等待消费者完成读取
    std::cout << "Producer process completed successfully!" << std::endl;
    
    // 8. 清理资源
    cudaFree(d_data);
    
    return EXIT_SUCCESS;
}