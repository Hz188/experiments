add_library(sub_object OBJECT sub.cpp)
target_link_libraries(sub_object PRIVATE common)
add_library(sub STATIC $<TARGET_OBJECTS:sub_object> $<TARGET_OBJECTS:common_object>) # 通过这个写法：sub.lib会通过sub.cpp和已经生成的common_object.o共同打包lib了
target_include_directories(sub PUBLIC ./) 