#include <iostream>

// 基类
class Base {
public:
    // 虚函数
    virtual void show() {
        std::cout << "Base class show function called." << std::endl;
    }
};

// 派生类
class Derived : public Base {
public:
    // 重写基类的虚函数
    void show() override {
        std::cout << "Derived class show function called." << std::endl;
    }
};

int main() {
    // 基类指针指向派生类对象
    Base *bptr = new Derived();

    // 调用虚函数，将根据对象的实际类型调用相应的函数版本
    bptr->show();  // 输出: Derived class show function called.

    //如果仍然想要调用 Base类(基类) 中的 show函数
    // 使用作用域解析运算符，调用基类中的show函数
    bptr->Base::show();  // 输出: Base class show function called.

    delete bptr;
    return 0;
}
