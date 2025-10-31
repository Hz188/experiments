cmake_minimum_required(VERSION 3.18)
project(NvshmemExamples LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_ARCHITECTURES 80)

# 查找CUDA和NVSHMEM
find_package(CUDA REQUIRED)
find_library(NVSHMEM_LIBRARY nvshmem HINTS /usr/lib/x86_64-linux-gnu/nvshmem/12 REQUIRED)
find_package(MPI REQUIRED)

# 查找LibTorch库
set(CMAKE_PREFIX_PATH /workspace/libtorch/)  # 修改为你的libtorch路径
find_package(Torch REQUIRED)

# 获取所有CUDA源文件
file(GLOB_RECURSE CUDA_SOURCES *.cu)

# 为每个源文件创建可执行目标
foreach(cuda_source ${CUDA_SOURCES})
    # 获取不带路径和扩展名的文件名
    get_filename_component(exe_name ${cuda_source} NAME_WE)
    
    # 添加可执行文件
    add_executable(${exe_name} ${cuda_source})
    
    # 设置CUDA编译选项
    set_target_properties(${exe_name} PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
        CUDA_RESOLVE_DEVICE_SYMBOLS ON
    )
    
    # 添加包含目录和链接库
    target_include_directories(${exe_name} PUBLIC
        /usr/include/nvshmem
        ${MPI_INCLUDE_PATH}
    )
    
    target_link_libraries(${exe_name} PUBLIC
        nvidia-ml
        cudart
        ${NVSHMEM_LIBRARY}
        cuda
        ${MPI_LIBRARIES}
        ${TORCH_LIBRARIES}
    )
    
    message(STATUS "Added target: ${exe_name}")
endforeach()