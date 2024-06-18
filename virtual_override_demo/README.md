# 多态中的一些关键语法

virtual 和 override

`virtual`: 初始设计的时候会用到，方面后续派生类重写功能

`override`: 显式标记 该函数是对基类virtual函数的重写

---

在C++中，虚函数是实现多态性的关键。多态性允许我们使用基类的指针或引用来调用派生类中重写的函数。只有将函数声明为虚函数，C++才会保证在运行时根据对象的实际类型来调用相应的函数版本。这就是为什么只有虚函数才能被派生类重写的原因。
下面是一个具体的案例，帮助您理解这一点：
```cpp
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
    delete bptr;
    return 0;
}
```
在这个案例中，有一个基类`Base`和一个派生类`Derived`。`Base`类中有一个虚函数`show`，而`Derived`类重写了这个函数。

在`main`函数中，我们创建了一个`Derived`类的对象，但是通过一个`Base`类的指针`bptr`来引用它。当我们调用`bptr->show()`时，由于`show`是一个虚函数，C++会确保调用的是`Derived`类中重写的`show`函数版本，而不是`Base`类中的版本。这就是多态性的体现。
如果`show`函数不是虚函数，那么无论`bptr`实际指向的是`Base`类的对象还是`Derived`类的对象，调用`bptr->show()`都会调用`Base`类中的`show`函数版本。这样，我们就无法通过基类指针或引用来调用派生类中重写的函数，从而失去了多态性。


