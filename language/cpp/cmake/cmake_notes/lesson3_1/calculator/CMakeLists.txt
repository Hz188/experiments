add_library(calculator STATIC calculator.cpp)
# target_include_directories(calculator PRIVATE ../add ../sub)  # add 和 sub 中的cmakelist文件中我们用PUBLIC进行include传递了，所以这里我们link了add、sub，不需要再include了
target_link_libraries(calculator PRIVATE add sub)
target_include_directories(calculator PUBLIC ./) # 传递性传递calculator的头文件