# explicit
---

<br>

explicit 是 C++ 中的一个关键字，用于修饰构造函数或转换函数，以防止隐式类型转换。具体来说，explicit 关键字的作用是：
1.**防止隐式类型转换**：
- 当构造函数被 explicit 修饰时，它只能用于显式调用，不能用于隐式类型转换。这意味着你不能通过赋值操作符或函数参数隐式地将一个类型转换为另一个类型。

2.**提高代码的可读性和安全性**：
- 使用 explicit 可以避免意外的类型转换，从而提高代码的可读性和安全性。它可以帮助你避免一些潜在的错误，特别是在构造函数只有一个参数的情况下。

<br>

## 示例

### 没有 explicit 的构造函数
```cpp
class MyClass {
 public:
  MyClass(int value) : value_(value) {}

 private:
  int value_;
};

int main() {
  MyClass obj = 42;  // 隐式类型转换，将 int 转换为 MyClass
  return 0;
}
```

在这个例子中，MyClass 的构造函数没有被 explicit 修饰，因此可以通过隐式类型转换将 int 转换为 MyClass。
实际上 `MyClass obj = 42;` 是 **等价于**  `MyClass temp(42);    MyClass obj = temp;`

>这里的 42 不是直接赋值给 obj，而是通过 隐式类型转换创建了一个临时 MyClass 对象，然后将这个临时对象赋值给 obj

<br>

### 使用 explicit 的构造函数
```cpp
class MyClass {
 public:
  explicit MyClass(int value) : value_(value) {}

 private:
  int value_;
};

int main() {
  // MyClass obj = 42;  // 编译错误，不能隐式转换
  MyClass obj(42);  // 显式调用构造函数
  return 0;
}
```
在这个例子中，MyClass 的构造函数被 explicit 修饰，因此不能通过隐式类型转换将 int 转换为 MyClass。你必须显式地调用构造函数。

<br>

### 在模板类中的使用
在你的代码中，explicit 关键字用于修饰模板类的构造函数：
```cpp
template <typename T = float>
class Tensor {
 public:
  explicit Tensor() = default;  // 默认构造函数

  explicit Tensor(uint32_t channels, uint32_t rows, uint32_t cols);
  explicit Tensor(uint32_t size);
  explicit Tensor(uint32_t rows, uint32_t cols);
};
```

这些构造函数被 explicit 修饰，以防止隐式类型转换。例如，你不能通过隐式类型转换将 uint32_t 转换为 Tensor 对象。

<br>

## 总结
- explicit 关键字用于修饰构造函数或转换函数，以防止隐式类型转换。
- 使用 explicit 可以提高代码的可读性和安全性，避免意外的类型转换。
- 在你的代码中，explicit 关键字用于修饰模板类的构造函数，以确保它们只能通过显式调用。