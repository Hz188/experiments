# include_directories(./add)
# include_directories(./sub)
# include_directories(./common)
# include_directories(./calculator)


# add_executable(lesson3_1 main.cpp 
#                         ./sub/sub.cpp
#                         ./add/add.cpp
#                         ./common/common.cpp
#                         ./calculator/calculator.cpp)
# ------------------------------------------------- 这样有坏处，没有减轻依赖，在cmake build log中把add.h sub.h什么的都暴露出来了，那么在main.cpp中可以直接include add.h没必要去用calculator类了


# 更好的方法：模块化一些

add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(common)
add_subdirectory(calculator)

add_executable(lesson3_1 main.cpp)
# target_include_directories(lesson3_1 PRIVATE ./calculator)  # calculator中用了PUBLIC，所以传递性，这里可以省略
target_link_libraries(lesson3_1 calculator)