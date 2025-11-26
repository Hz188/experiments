# C++ TCP Socket 通信示例

这是一个简单的C++ TCP Socket服务器和客户端通信的示例代码。

## 文件说明

- `tcp_server.cpp` - TCP服务器实现
- `tcp_client.cpp` - TCP客户端实现
- `CMakeLists.txt` - 构建配置文件

## 构建步骤

1. 进入socket目录：
```bash
cd cpp/library/socket
```

2. 创建构建目录并编译：
```bash
mkdir build
cd build
cmake ..
make
```

## 运行方法

### 启动服务器（在终端1中）：
```bash
./tcp_server
```

### 启动客户端（在终端2中）：
```bash
./tcp_client
```

## 功能特性

### 服务器功能：
- 监听指定端口（默认8080）
- 支持多个客户端同时连接
- 为每个客户端创建独立线程处理
- 支持"quit"命令来断开连接

### 客户端功能：
- 连接到指定服务器IP和端口
- 发送消息给服务器
- 接收服务器响应
- 支持"quit"命令退出

## 示例交互

服务器输出：
```
TCP Server started on port 8080
Waiting for connections...
New client connected!
Received from client: Hello Server
Received from client: Test message
Client disconnected
```

客户端输出：
```
Connecting to server 127.0.0.1:8080...
Connected to server!
Welcome to TCP Server! Type 'quit' to exit.
Enter message (type 'quit' to exit): Hello Server
Server received: Hello Server
Enter message (type 'quit' to exit): Test message  
Server received: Test message
Enter message (type 'quit' to exit): quit
Goodbye!
```

## 注意事项

- 默认使用本地回环地址127.0.0.1
- 默认端口为8080，如端口被占用可修改代码中的端口号
- 需要在Linux环境下运行（使用了POSIX socket API）