#include <iostream>
int main() {
    char a = 0xff;
    if(a == 0xff){
        std::cout << "same\n";
    } else{
        std::cout << "different\n";
    }

    if(a == (char)0xff){
        std::cout << "same\n";
    } else{
        std::cout << "different\n";
    }

}

/*
    第一个if else
        0xff是无符号数，a是有符号数，二者比较会先转换int，进行数值提升到相同类型，然后比较，一个是0xffffffff一个是0x000000ff，所以不等
    第二个if else
        两个都是char类型了，都是-1，自然没毛病了

    这个现象的主要原因就是数的二进制表示：补码，0xff在不同的数据类型解释下，对应不同的值，-1或者255
        
*/