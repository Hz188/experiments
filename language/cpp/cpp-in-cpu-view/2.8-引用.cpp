// 指针变量 vs 引用变量
void func1()
{
    int a = 1;
    int* p = &a;
    *p = 2;
}


void func2()
{
    int a = 1;
    int& r = a;
    r = 2;
}

//指针参数 vs 引用参数
void func3(int* p) {
    *p = 2;
}

void func4(int& r) {
    r = 2;
}

// 指针返回值 vs 引用返回值

int* func5() {
    int a = 1;
    int* p = &a;
    return p;
}

int& func6() {
    int a = 1;
    int& r = a;
    return r;
}
int main() {
    int a = 1;

    func3(&a);
    func4(a);
}

/*
    func1 func2的汇编代码完全相同，所以可以知道
        引用本质还是指针，又是一个语法优化，让我们更加便捷的使用，省略掉了一些指针操作
            指针可以赋值为空，但引用不行，必须赋值
            指针可以改变指向，引用不行（引用是一个指针常量） -> int* const p = &a 这就是引用的本质
            存在指针的指针，不存在引用的引用
            指针有自己的内存空间，引用没有
        我们对引用变量的读写操作，实际上就是对指针变量的*读，*写操作
        在CPU眼中，引用和指针没有任何的区别
    func3 func4的函数体、调用对应的CPU指令也完全一样
        所以可以知道，引用参数的传递本质还是个指针的地址值的传递
    func5 func6对应的CPU指令也完全一样
        所以可以知道，引用返回值本质上也是地址，但这里引用、指针都会发生悬挂，仅作为举例学习
*/