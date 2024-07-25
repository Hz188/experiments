#include <iostream>
#include <cstdio>
using namespace std;
__global__ void hello_world()
{
    printf("GPU: Hello world!\n");
}

int main(int argc,char **argv)
{
    printf("CPU: Hello world!\n");
    hello_world<<<1,10>>>();

    cudaDeviceReset();//if no this line ,it can not output hello world from gpu
    return 0;
}