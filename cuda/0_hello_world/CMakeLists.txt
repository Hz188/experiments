cmake_minimum_required(VERSION 3.16)
project(0_helloworld CUDA)
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 70 75 80)
endif(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
set(CMAKE_CUDA_STANDARD 17)

add_executable(hello_world hello_world.cu)
add_executable(test test.cu)

set_target_properties(hello_world PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)