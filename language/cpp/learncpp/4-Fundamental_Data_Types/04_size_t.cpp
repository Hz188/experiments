#include <iostream>
#include <cstddef>
int main()
{
    std::cout << sizeof(int) << '\n';
    std::cout << "sizeof 的返回值类型是 std::size_t，定义为无符号实现的整数类型，一般用来表示对象的length和size\n";

    return 0;
}