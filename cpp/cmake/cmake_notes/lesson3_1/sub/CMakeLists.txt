add_library(sub STATIC sub.cpp)
# target_include_directories(sub PRIVATE ../common) # 这里注释掉是因为在common目录下的cmakelist文件中，我们target_include_directory了一个interface，其含义就是我们sub link了common，那么common里面那个include目录我们也可用（传递性）
target_link_libraries(sub PRIVATE common)


target_include_directories(sub PUBLIC ./)  # 这一行的目的是：我们calculator的cmakelist中 依赖了add, sub，那么利用PUBLIC的传递性质，calculator就可以省略那个头文件