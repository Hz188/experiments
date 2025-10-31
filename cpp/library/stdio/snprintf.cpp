
#include <stdio.h>

int main() {
    char buffer[20];
    int ret = snprintf(buffer, sizeof(buffer), "Hello %s, number %d", "World", 2025);

    if (ret >= sizeof(buffer)) {
        printf("Output was truncated!\n");
    } else {
        printf("Formatted string: %s\n", buffer);
    }

    return 0;
}


/*
int snprintf(char *str, size_t size, const char *format, ...);
args:
    str: 指向目标字符数组的指针，用于存储格式化后的字符串
    size: 目标缓冲区的大小（包括结尾的 ⁠\0 字符）
    format: 格式字符串，类似 ⁠printf 的格式控制
    ...: 变长参数，根据格式字符串提供对应的值
description:
    返回写入到字符串（不包括终止符 ⁠\0）所需的字符数（不受缓冲区大小限制）
    如果返回值 ≥ ⁠size，表示输出被截断了。
*/