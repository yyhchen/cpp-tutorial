#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

// 定义一个命名空间
namespace MyNamespace {

// 定义一个基类
    class Base {
    public:
        // 构造函数
        Base() {
            std::cout << "Base constructor" << std::endl;
        }

        // 析构函数
        virtual ~Base() {
            std::cout << "Base destructor" << std::endl;
        }

        // 虚函数
        virtual void virtualFunction() {
            std::cout << "Base virtualFunction" << std::endl;
        }

        // 纯虚函数
        virtual void pureVirtualFunction() = 0;

        // 静态成员函数
        static void staticFunction() {
            std::cout << "Base staticFunction" << std::endl;
        }

        // 常量成员函数
        void constFunction() const {
            std::cout << "Base constFunction" << std::endl;
        }

        // 重载运算符
        Base& operator=(const Base& other) {
            if (this != &other) {
                // 复制操作
            }
            return *this;
        }

    protected:
        // 保护成员变量
        int protectedVar = 0;
    };

// 定义一个派生类
    class Derived : public Base {
    public:
        // 构造函数
        Derived() {
            std::cout << "Derived constructor" << std::endl;
        }

        // 析构函数
        ~Derived() override {
            std::cout << "Derived destructor" << std::endl;
        }

        // 重写虚函数
        void virtualFunction() override {
            std::cout << "Derived virtualFunction" << std::endl;
        }

        // 实现纯虚函数
        void pureVirtualFunction() override {
            std::cout << "Derived pureVirtualFunction" << std::endl;
        }

        // 友元函数
        friend void friendFunction(Derived& d);

    private:
        // 私有成员变量
        std::string privateVar = "Derived privateVar";
    };

// 友元函数定义
    void friendFunction(Derived& d) {
        std::cout << "Friend function accessing privateVar: " << d.privateVar << std::endl;
    }

} // namespace MyNamespace

// 模板类
template <typename T>
class TemplateClass {
public:
    // 模板成员函数
    T templateFunction(T value) {
        return value * 2;
    }
};

// 函数模板
template <typename T>
T functionTemplate(T value) {
    return value * 3;
}

// 主函数
int main() {
    using namespace MyNamespace;

    // 使用命名空间中的类
    Base* basePtr = new Derived();
    basePtr->virtualFunction();
    basePtr->pureVirtualFunction();
    basePtr->constFunction();
    Base::staticFunction();
    delete basePtr;

    // 使用模板类
    TemplateClass<int> tc;
    std::cout << "TemplateClass result: " << tc.templateFunction(5) << std::endl;

    // 使用函数模板
    std::cout << "FunctionTemplate result: " << functionTemplate(5) << std::endl;

    // 使用友元函数
    Derived d;
    friendFunction(d);

    return 0;
}
