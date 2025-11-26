#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <algorithm>

class TCPServer {
private:
    int server_fd;
    struct sockaddr_in address;
    std::vector<int> client_sockets;

public:
    TCPServer(int port = 8080) {
        // 创建socket文件描述符
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        // 设置socket选项，允许地址重用
        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        // 绑定socket到端口
        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }

        // 开始监听连接
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }

        std::cout << "TCP Server started on port " << port << std::endl;
    }

    void handle_client(int client_socket) {
        char buffer[1024] = {0};
        std::string welcome_msg = "Welcome to TCP Server! Type 'quit' to exit.\n";
        send(client_socket, welcome_msg.c_str(), welcome_msg.length(), 0);

        while (true) {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(client_socket, buffer, 1024);
            
            if (valread <= 0) {
                std::cout << "Client disconnected" << std::endl;
                break;
            }

            std::string message(buffer);
            std::cout << "Received from client: " << message;

            // 移除换行符
            message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
            message.erase(std::remove(message.begin(), message.end(), '\r'), message.end());

            if (message == "quit") {
                std::string goodbye_msg = "Goodbye!\n";
                send(client_socket, goodbye_msg.c_str(), goodbye_msg.length(), 0);
                break;
            }

            std::string response = "Server received: " + message + "\n";
            send(client_socket, response.c_str(), response.length(), 0);
        }

        // 从客户端列表中移除并关闭socket
        auto it = std::find(client_sockets.begin(), client_sockets.end(), client_socket);
        if (it != client_sockets.end()) {
            client_sockets.erase(it);
        }
        close(client_socket);
    }

    void start() {
        while (true) {
            int client_socket;
            int addrlen = sizeof(address);
            
            std::cout << "Waiting for connections..." << std::endl;
            
            if ((client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                continue;
            }

            std::cout << "New client connected!" << std::endl;
            client_sockets.push_back(client_socket);

            // 为每个客户端创建新线程
            std::thread client_thread(&TCPServer::handle_client, this, client_socket);
            client_thread.detach(); // 分离线程，让其独立运行
        }
    }

    ~TCPServer() {
        // 关闭所有客户端连接
        for (int client_socket : client_sockets) {
            close(client_socket);
        }
        close(server_fd);
    }
};

int main() {
    TCPServer server(8081);
    server.start();
    return 0;
}