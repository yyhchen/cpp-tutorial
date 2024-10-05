#include <iostream>

// 模板函数声明，可以接受任何类型的两个参数
template <typename T=float>
T add(T a, T b) {
    return a + b;
}

// 模板函数特化，当 T 为 int 类型时，使用这个函数
template <>
int add<int>(int a, int b) {
    return a + b;
}

int main() {
    // 使用模板函数添加两个整数
    int sum1 = add(10, 20);
    std::cout << "The sum of 10 and 20 is: " << sum1 << std::endl;

    // 使用模板函数添加两个浮点数
    float sum2 = add(10.5f, 20.5f);
    std::cout << "The sum of 10.5 and 20.5 is: " << sum2 << std::endl;

    int sum3 = add<int>(10.1, 20); // 使用默认类型 float
    std::cout << "The sum3 is: " << sum3 << std::endl;

    return 0;
}
