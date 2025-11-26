cmake_minimum_required(VERSION 3.18)
project(cuda_ipc_demo)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找CUDA
find_package(CUDA REQUIRED)

# 启用CUDA语言
enable_language(CUDA)

# 设置CUDA编译选项
set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# 设置CUDA架构
if(NOT CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 52 60 61 70 75 80 86)
endif()

# 添加编译定义
add_definitions(-DCUDA_IPC_DEMO)

# 创建生产者可执行文件
add_executable(producer producer.cu)
target_link_libraries(producer ${CUDA_LIBRARIES})
target_include_directories(producer PRIVATE ${CUDA_INCLUDE_DIRS})
set_target_properties(producer PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
)

# 创建消费者可执行文件
add_executable(consumer consumer.cu)
target_link_libraries(consumer ${CUDA_LIBRARIES})
target_include_directories(consumer PRIVATE ${CUDA_INCLUDE_DIRS})
set_target_properties(consumer PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
)

# 设置输出目录
set_target_properties(producer consumer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# 打印配置信息
message(STATUS "CUDA Version: ${CUDA_VERSION}")
message(STATUS "CUDA Include Dirs: ${CUDA_INCLUDE_DIRS}")
message(STATUS "CUDA Libraries: ${CUDA_LIBRARIES}")
message(STATUS "CUDA Architectures: ${CMAKE_CUDA_ARCHITECTURES}")