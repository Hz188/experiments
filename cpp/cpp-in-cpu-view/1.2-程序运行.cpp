#include <cstdio>
#include <cstdlib>

char a[] = "password";

int main() {
    int b = 2;
    int* c = (int*) malloc(4);
    *c = 0x11223344;

    printf("%p, %p, %p, %p\n", &a, &b, c, main);
}

// output:
// 0x102cc8000, 0x16d13eb6c, 0x12de05e00, 0x102cc3f00
/*
    可以看出，分别对应了四个内存区域，由低到高，分别是
    1. .text 代码段
    2. .data 数据段
    3. .heap 堆区
    4. .stack 堆栈区 
*/