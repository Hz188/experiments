#include <stdio.h>
#include <stdlib.h>

// int main() {
//     cout << "main" << endl;
//     return 0;
// }

void func() {
    exit(0);
}

/*
    这两个函数的汇编代码完全相同
        只是默认的入口是main，我们也可以通过设置-efunc指定程序起点：g++ -nostartfiles -efunc test.c可以改变
        (macos不行，需要x86上进行)
*/