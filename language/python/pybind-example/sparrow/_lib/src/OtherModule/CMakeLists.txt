set(CMAKE_CXX_STANDARD 17)
set (Python_ROOT_DIR "/Users/genghaozhe/anaconda3/envs/dlsys")
find_package(Python 3.11 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED) #找到依赖
pybind11_add_module(OtherModule OtherModule.cpp function1.cpp function2.cpp)