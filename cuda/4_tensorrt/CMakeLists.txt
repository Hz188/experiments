cmake_minimum_required(VERSION 3.16)
project(4_tensorrt)
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 70 75 80)
endif(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
set(CMAKE_CXX_STANDARD 17)

set(
        SAMPLES_COMMON_SOURCES
        E:/cudaEnv/TensorRT-10.0.0.6.Windows10.win10.cuda-12.4/TensorRT-10.0.0.6/samples/common/logger.cpp
        E:/cudaEnv/TensorRT-10.0.0.6.Windows10.win10.cuda-12.4/TensorRT-10.0.0.6/samples/common/getopt.c
)
# add TensorRT8
include_directories(E:/cudaEnv/TensorRT-10.0.0.6.Windows10.win10.cuda-12.4/TensorRT-10.0.0.6/samples)
include_directories(E:/cudaEnv/TensorRT-10.0.0.6.Windows10.win10.cuda-12.4/TensorRT-10.0.0.6/include)
include_directories(E:/cudaEnv/TensorRT-10.0.0.6.Windows10.win10.cuda-12.4/TensorRT-10.0.0.6/samples/common)
add_executable(trt_mnist sampleOnnxMNIST.cpp ${SAMPLES_COMMON_SOURCES})
set(TENSORRT_LIB_PATH E:/cudaEnv/TensorRT-10.0.0.6.Windows10.win10.cuda-12.4/TensorRT-10.0.0.6/lib)
file(GLOB LIBS "${TENSORRT_LIB_PATH}/*.lib")

# add CUDA
find_package(CUDA 12.4 REQUIRED)
include_directories(${CUDA_INCLUDE_DIRS})

# link
target_link_libraries(trt_mnist ${LIBS} ${CUDA_LIBRARIES})
