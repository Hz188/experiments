# add_library(common STATIC common.cpp)
# 这里和lesson3_1重名了，所以根目录下CMakeLists.txt中这两个子目录只能开一个，不能同时开

add_library(common_object_shared OBJECT common.cpp) 
set_target_properties(common_object_shared PROPERTIES POSITION_INDEPENDENT_CODE ON)
add_library(common_object OBJECT common.cpp) # 通过OBJECT，可以避免直接打包成库文件，而是得到.o文件，方便我们合并最终的lib
add_library(common STATIC $<TARGET_OBJECTS:common_object>)
target_include_directories(common PUBLIC ./)