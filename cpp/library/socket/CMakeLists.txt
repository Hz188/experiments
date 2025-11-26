cmake_minimum_required(VERSION 3.10)
project(TCP_Socket_Demo)

set(CMAKE_CXX_STANDARD 11)

# 可执行文件
add_executable(tcp_server tcp_server.cpp)
add_executable(tcp_client tcp_client.cpp)

# 链接必要的库（在Linux下通常不需要额外链接）
target_link_libraries(tcp_server pthread)
target_link_libraries(tcp_client pthread)

# 编译选项
target_compile_options(tcp_server PRIVATE -Wall -Wextra)
target_compile_options(tcp_client PRIVATE -Wall -Wextra)

message(STATUS "TCP Socket Demo project configured successfully")
message(STATUS "To build: make")
message(STATUS "To run server: ./tcp_server")
message(STATUS "To run client: ./tcp_client")