#include <iostream>

class Fraction {
public:
    explicit Fraction(int numerator, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
        std::cout << "构造函数被调用，分子: " << m_numerator << " 分母: " << m_denominator << std::endl;
    }

    // 其他成员函数和操作符重载...

private:
    int m_numerator;   // 分子
    int m_denominator; // 分母
};

int main() {
    Fraction f1(3, 4); // 正确，直接调用构造函数

//     Fraction f2 = 5;  // 如果没有使用explicit，这将隐式转换并调用构造函数
    // 使用了explicit后，这行代码将编译错误

    return 0;
}
