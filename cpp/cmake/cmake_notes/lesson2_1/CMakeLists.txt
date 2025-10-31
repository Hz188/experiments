add_subdirectory(add)

include_directories(./lib)
# 方式1
# link_libraries(E:/code/CMake_Notes/lesson2_1/lib/add_static.lib)
# 方式2: step1，先给出lib目录
link_directories(E:/code/CMake_Notes/lesson2_1/lib)  

add_executable(lesson2_1 main.cpp)
# 方式2: step2，link具体的lib
target_link_libraries(lesson2_1 add_static.lib)
