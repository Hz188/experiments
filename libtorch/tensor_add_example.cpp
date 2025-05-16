#include <torch/torch.h>
#include <iostream>

int main() {
    // 创建两个张量
    torch::Tensor a = torch::ones({2, 2});
    torch::Tensor b = torch::randn({2, 2});
    
    // 张量相加
    torch::Tensor c = a + b;
    
    // 打印结果
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    
    return 0;
}