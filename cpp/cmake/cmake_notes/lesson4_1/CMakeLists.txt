add_subdirectory(common)
add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(calculator)

add_executable(lesson4_1 main.cpp)
target_link_libraries(lesson4_1 calculator)

# 这节课的例子解决的是：3_1中，我们打包静态库，4个目录下，对应了四个lib，本质上还是分开的
# 我们想达到的是效果是
#   main         要用 calculator
#   calculator   要用 add 和 sub
#   sub, add     要用 common

# 3_1的方案本质上是打了四个lib，main直接用四个
# 4_1我们想打的是最终的一个calculator的lib（他包含了所有前面的依赖，合并为一个lib了）
# main 用这一个lib就可以运行