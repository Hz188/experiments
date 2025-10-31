#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[256];  // 缓冲区大小一般取256或更大
    if (gethostname(hostname, sizeof(hostname)) == 0) { // POSIX 标准的系统调用，用于获取当前主机名
        printf("Host name: %s\n", hostname);
    } else {
        perror("gethostname error");
        return 1;
    }
    return 0;
}
// Host name: ab.cd.ef.com
