# CUDA IPC Communication Demo

这个演示项目展示了如何在两个不同的进程之间使用CUDA IPC (Inter-Process Communication) API共享GPU内存。

## 项目结构

```
cuda/ipc/
├── producer.cu      # 生产者进程 - 创建并共享GPU内存
├── consumer.cu      # 消费者进程 - 访问共享的GPU内存
├── CMakeLists.txt   # CMake构建配置
├── run_demo.sh      # 自动化执行脚本
└── README.md        # 本文档
```

## 功能特性

- **进程间GPU内存共享**: 使用CUDA IPC API实现跨进程GPU内存访问
- **数据验证**: 自动验证共享数据的正确性
- **错误处理**: 完善的CUDA错误检查和资源清理
- **自动化构建**: 提供CMake配置和执行脚本

## 系统要求

- NVIDIA GPU (支持CUDA IPC)
- CUDA Toolkit 11.0或更高版本
- CMake 3.18或更高版本
- Linux操作系统

## 编译和运行

### 方法1: 使用自动化脚本（推荐）

```bash
cd cuda/ipc
chmod +x run_demo.sh
./run_demo.sh
```

### 方法2: 手动编译和运行

```bash
# 1. 创建构建目录
mkdir -p build && cd build

# 2. 配置CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# 3. 编译
make -j$(nproc)

# 4. 运行demo
# 终端1: 启动生产者
./producer &

# 终端2: 启动消费者
./consumer
```

## 工作原理

1. **生产者进程**:
   - 分配GPU内存
   - 写入测试数据
   - 生成IPC句柄并写入文件
   - 等待消费者进程

2. **消费者进程**:
   - 读取IPC句柄文件
   - 通过句柄打开共享内存
   - 读取并验证数据
   - 关闭内存句柄

## 预期输出

成功运行时，你应该看到类似以下的输出：

```
=== CUDA IPC Communication Demo ===

Producer process started...
Allocated 4194304 bytes on GPU
Data copied to GPU memory
IPC handle generated
IPC handle written to ipc_handle.txt
Waiting for consumer process...
Producer process completed successfully!

Consumer process started...
IPC handle read from ipc_handle.txt
IPC memory handle opened successfully
Data copied from GPU to host
✓ Data validation PASSED! All 1048576 elements are correct.
Sample data points:
  [0] = 0
  [1] = 0.001
  [2] = 0.002
  ...
Consumer process completed!

=== Demo Results ===
✓ CUDA IPC Demo completed successfully!
```

## 技术细节

### CUDA IPC API使用

- `cudaIpcGetMemHandle()`: 获取GPU内存的IPC句柄
- `cudaIpcOpenMemHandle()`: 通过IPC句柄打开共享内存
- `cudaIpcCloseMemHandle()`: 关闭IPC内存句柄

### 数据验证

demo使用简单的线性数据模式进行验证：
- 数据范围: 0 到 1047.575
- 精度要求: 1e-6
- 数据大小: 1M float元素 (4MB)

### 注意事项

1. **GPU兼容性**: 确保GPU支持P2P (Peer-to-Peer)通信
2. **内存管理**: 确保正确的内存分配和释放
3. **进程同步**: 本demo使用简单的sleep进行同步，生产环境应使用更robust的同步机制
4. **错误处理**: 所有CUDA调用都有错误检查

## 故障排除

### 常见问题

1. **编译错误**:
   - 检查CUDA版本是否兼容
   - 确认CMake版本 >= 3.18
   - 验证GPU架构设置

2. **运行时错误**:
   - 确认GPU驱动已正确安装
   - 检查GPU是否支持IPC功能
   - 验证CUDA运行时环境

3. **IPC错误**:
   - 确保两个进程在同一GPU上运行
   - 检查IPC句柄文件权限
   - 验证内存对齐要求

### 调试建议

- 使用`cuda-memcheck`检查内存错误
- 启用CUDA详细错误信息
- 检查系统日志中的GPU相关错误

## 扩展建议

1. **多GPU支持**: 扩展到多GPU环境
2. **性能测试**: 添加带宽和延迟测试
3. **高级同步**: 使用信号量或事件进行进程同步
4. **数据类型**: 支持更多数据类型和结构
5. **网络扩展**: 结合MPI或RDMA实现网络IPC

## 参考资料

- [CUDA IPC Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#ipc)
- [CUDA Runtime API](https://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__IPC.html)
- [Multi-Process Service](https://docs.nvidia.com/deploy/mps/index.html)