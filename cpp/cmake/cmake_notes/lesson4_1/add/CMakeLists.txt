add_library(add_object OBJECT add.cpp)
target_link_libraries(add_object PRIVATE common)
add_library(add STATIC $<TARGET_OBJECTS:add_object> $<TARGET_OBJECTS:common_object>) # 通过这个写法：add.lib会通过add.cpp和已经生成的common_object.o共同打包lib了
target_include_directories(add PUBLIC ./) 