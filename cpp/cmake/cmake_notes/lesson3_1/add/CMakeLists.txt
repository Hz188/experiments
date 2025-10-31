add_library(add STATIC add.cpp)
# PUBLIC PRIVATE INTERFACE
# target_include_directories(add PRIVATE ../common) #这里注释掉是因为在common目录下的cmakelist文件中，我们target_include_directory了一个interface，其含义就是我们add link了common，那么common里面那个include目录我们也可用（也就省了这行）
target_link_libraries(add PRIVATE common)

# PRIVATE: 说明后面的../common只对add生效
# PUBLIC: 说明后面的../common除了对add生效，还对用到add的东西生效
# INTERFACE: 说明后面的../common只对用到add的东西生效
# 比如PUBLIC的情况下，calculator会用add，那么build的g++命令中，-I...add目录之外，还会有-I...common目录

target_include_directories(add PUBLIC ./)  # 这一行的目的是：我们calculator的cmakelist中 依赖了add, sub，那么利用PUBLIC的传递性质，就可以省略那个头文件