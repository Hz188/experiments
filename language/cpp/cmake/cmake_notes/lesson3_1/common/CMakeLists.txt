add_library(common STATIC common.cpp)
# target_include_directories(common INTERFACE ./)  # 是这样的，我们不能单单看common为一个lib，而是要看做一个target，这个target携带了头相关的信息
target_include_directories(common PUBLIC ./)  
# 根据上面的目的：是为了传递给用common的target，那么显然，我们用PUBLIC也是可以的，PRIVATE是不行的