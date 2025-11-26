#!/bin/bash

# CUDA IPC Demo执行脚本

echo "=== CUDA IPC Communication Demo ==="
echo

# 检查CUDA环境
if ! command -v nvcc &> /dev/null; then
    echo "Error: CUDA compiler (nvcc) not found. Please install CUDA toolkit."
    exit 1
fi

# 创建构建目录
echo "Creating build directory..."
mkdir -p build
cd build

# 配置CMake
echo "Configuring CMake..."
cmake .. -DCMAKE_BUILD_TYPE=Release

if [ $? -ne 0 ]; then
    echo "Error: CMake configuration failed."
    exit 1
fi

# 编译项目
echo "Building project..."
make -j$(nproc)

if [ $? -ne 0 ]; then
    echo "Error: Build failed."
    exit 1
fi

echo
echo "Build completed successfully!"
echo

# 清理之前的IPC句柄文件
rm -f ../ipc_handle.txt

# 运行demo
echo "Running CUDA IPC Demo..."
echo

# 启动生产者进程（后台运行）
echo "Starting producer process..."
./producer &
PRODUCER_PID=$!

# 等待一秒确保生产者进程完成初始化
sleep 1

# 启动消费者进程
echo "Starting consumer process..."
./consumer
CONSUMER_RESULT=$?

# 等待生产者进程完成
wait $PRODUCER_PID
PRODUCER_RESULT=$?

echo
echo "=== Demo Results ==="
if [ $PRODUCER_RESULT -eq 0 ] && [ $CONSUMER_RESULT -eq 0 ]; then
    echo "✓ CUDA IPC Demo completed successfully!"
else
    echo "✗ Demo failed with errors."
    echo "  Producer exit code: $PRODUCER_RESULT"
    echo "  Consumer exit code: $CONSUMER_RESULT"
fi

# 清理临时文件
rm -f ../ipc_handle.txt

echo
echo "Demo finished."