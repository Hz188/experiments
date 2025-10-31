add_subdirectory(add)

include_directories(./bin)
# 这行定义实现跨平台的库导出，如果注释，则为windows动态库导出，解除注释则为Linux平台动态库导出
# add_definitions(-DLINUX)  
add_executable(lesson2_2 main.cpp)
target_link_libraries(lesson2_2 E:/code/CMake_Notes/lesson2_2/bin/add_shared.lib)