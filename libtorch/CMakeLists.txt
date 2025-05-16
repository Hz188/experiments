cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(torch_example)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 查找LibTorch库
set(CMAKE_PREFIX_PATH /workspace/libtorch/)  # 修改为你的libtorch路径
find_package(Torch REQUIRED)

# 添加可执行文件
add_executable(torch_example tensor_add_example.cpp)

# 链接LibTorch库
target_link_libraries(torch_example ${TORCH_LIBRARIES})