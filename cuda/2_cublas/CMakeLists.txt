project(2_cublas)
set(CMAKE_CUDA_STANDARD 17)
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 70 75 80)
endif(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
include_directories(.)
add_executable(main main.cpp MyCublas.cu)

find_package(CUDA 12.4 REQUIRED)
include_directories(${CUDA_INCLUDE_DIRS})

# link
target_link_libraries(main cublas)
