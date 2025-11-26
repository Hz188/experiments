#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class TCPClient {
private:
    int sock;
    struct sockaddr_in serv_addr;

public:
    TCPClient(const std::string& ip = "127.0.0.1", int port = 8080) {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket creation error");
            exit(EXIT_FAILURE);
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);

        // 将IPv4地址从文本转换为二进制形式
        if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
            perror("invalid address/ address not supported");
            exit(EXIT_FAILURE);
        }

        std::cout << "Connecting to server " << ip << ":" << port << "..." << std::endl;
        
        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connection failed");
            exit(EXIT_FAILURE);
        }

        std::cout << "Connected to server!" << std::endl;
    }

    void start() {
        char buffer[1024] = {0};
        
        // 读取欢迎消息
        int valread = read(sock, buffer, 1024);
        std::cout << buffer;

        while (true) {
            std::cout << "Enter message (type 'quit' to exit): ";
            std::string message;
            std::getline(std::cin, message);

            if (message == "quit") {
                send(sock, message.c_str(), message.length(), 0);
                break;
            }

            send(sock, message.c_str(), message.length(), 0);
            
            memset(buffer, 0, sizeof(buffer));
            valread = read(sock, buffer, 1024);
            std::cout << buffer;
        }
    }

    ~TCPClient() {
        close(sock);
    }
};

int main() {
    TCPClient client("127.0.0.1", 8081);
    client.start();
    return 0;
}