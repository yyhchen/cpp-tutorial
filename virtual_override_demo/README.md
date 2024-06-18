# 多态中的一些关键语法

virtual 和 override

`virtual`: 初始设计的时候会用到，方面后续派生类重写功能

`override`: 显式标记 该函数是对基类virtual函数的重写

---

<br>

## 1️⃣ 多态使用(virtual、override)

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


---

<br>
<br>
<br>


## 2️⃣ 在函数后面加 `const`
在C++中，`const`关键字用于声明一个函数，表示该函数不会修改类的成员变量。当你在函数后面加上`const`时，你是在告诉编译器这个函数是“常量成员函数”，它承诺不会改变调用它的对象的状态。
`override`关键字用于指示编译器，这个函数是重写的基类中的虚函数。它是在C++11标准中引入的，用于提高代码的可读性和可维护性，同时也允许编译器检查是否正确地重写了基类中的函数。
下面是一个例子，说明`const`和`override`的用法：
```cpp
class Base {
public:
    virtual void show() const {
        std::cout << "Base class show function called." << std::endl;
    }
};
class Derived : public Base {
public:
    void show() const override {
        std::cout << "Derived class show function called." << std::endl;
    }
};
```
在这个例子中，`Base`类中的`show`函数被声明为`const`，这意味着它不会修改`Base`类的任何成员变量。`Derived`类中的`show`函数重写了基类的`show`函数，并且也声明为`const`，同时使用了`override`关键字来指示这是对基类函数的重写。
至于为什么要在函数后面加`const`，原因有以下几点：
1. **明确意图**：告诉其他程序员这个函数不会修改对象的状态，这有助于理解代码的意图。
2. **安全性**：如果一个`const`成员函数试图修改成员变量，编译器将会报错，这样可以防止意外的修改。
3. **可调用性**：`const`成员函数可以被`const`对象调用，这增加了函数的可用性。
   即使加了`const`，函数仍然可以执行许多操作，比如读取成员变量的值、调用其他`const`成员函数、修改非成员变量的值等。`const`只是限制了函数对调用对象本身的修改。
