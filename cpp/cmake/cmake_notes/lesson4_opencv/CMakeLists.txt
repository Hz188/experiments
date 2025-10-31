find_package(OpenCV REQUIRED) # 以Opencv第三方库为例，库提供了一个OpenCVConfig.cmake
# 所以find package所做的操作就是，OpenCV(Xxx)这个前缀 对应的XxxConfig.cmake
# 注意大小写
add_executable(lesson4_opencv main.cpp)
target_include_directories(lesson4_opencv PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(lesson4_opencv ${OpenCV_LIBS})

message("========${OpenCV_INCLUDE_DIRS}========")