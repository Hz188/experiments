include_directories(E:/env/opencv/build/include)

add_executable(lesson2_opencv main.cpp)

target_link_libraries(lesson2_opencv "E:/env/opencv/build/x64/vc16/lib/opencv_world490d.lib")