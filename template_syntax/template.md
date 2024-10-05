# template使用

---

<br>

在 C++ 中，模板（template）是一种允许你编写与类型无关的代码的机制。模板可以应用于类和函数，使得它们能够处理多种不同的数据类型，而不需要为每种类型编写特定的代码。模板的关键在于它允许类型作为参数传递，从而实现代码的泛化。
### 类模板
类模板的语法如下：
```cpp
template <typename T>
class MyClass {
  T value;
public:
  MyClass(T v) : value(v) {}
  T get() const { return value; }
};
```
在这个例子中，`MyClass` 是一个模板类，它有一个类型参数 `T`。你可以用任何类型来实例化这个类，例如 `MyClass<int>` 或 `MyClass<std::string>`。
> 这里的 `MyClass<int>` 意思是： 创建一个 MyClass 的实例，其中 T 被替换为 int 类型。这个类的实例将可以存储整数。

### 函数模板
函数模板的语法如下：
```cpp
template <typename T>
T add(T a, T b) {
  return a + b;
}
```
这个 `add` 函数可以接受两个相同类型的参数并返回它们的和。你可以在调用时指定模板参数，也可以让编译器自动推断。
### 使用案例
假设你想要写一个简单的数据结构来存储一系列的值，这些值可以是整数、浮点数或其他任何类型。你可以使用模板来实现这个功能：
```cpp
template <typename T>
class Stack {
  std::vector<T> elements;
public:
  void push(T element) {
    elements.push_back(element);
  }
  T pop() {
    T element = elements.back();
    elements.pop_back();
    return element;
  }
  bool empty() const {
    return elements.empty();
  }
};
```
现在你可以创建不同类型的 `Stack` 对象：
```cpp
Stack<int> intStack;
intStack.push(1);
intStack.push(2);
std::cout << intStack.pop() << std::endl; // 输出 2
Stack<std::string> stringStack;
stringStack.push("Hello");
stringStack.push("World");
std::cout << stringStack.pop() << std::endl; // 输出 "World"
```
在这个例子中，`Stack` 类是一个模板类，它可以用任何类型来实例化。这使得你能够用相同的方式来处理不同类型的数据，而不需要为每种类型编写重复的代码。
