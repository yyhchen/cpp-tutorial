# callback机制

顺带复习一下 `std::function` 与 `lambda` 表达式 结合使用的案例。

通俗的理解 `callback` 就是，函数作为参数 传递给另一个函数。

---


 在编程中，"callback"（回调）是一种常见的编程模式，指的是**将一个函数（或函数对象）作为参数传递给另一个函数，并在某个特定事件或条件发生时调用这个函数**。回调函数通常用于异步操作、事件处理、排序、过滤等场景。

### 回调的基本概念

1. **定义回调函数**：
   - 回调函数是一个普通的函数，或者是一个函数对象（如 lambda 表达式、仿函数等）。
   - 回调函数通常具有特定的签名（参数和返回值类型），以便被调用者正确地调用。

2. **传递回调函数**：
   - 回调函数作为参数传递给另一个函数。这个接收回调函数的函数通常被称为“高阶函数”或“回调处理器”。

3. **调用回调函数**：
   - 在高阶函数内部，当某个事件或条件满足时，调用传递进来的回调函数。

### 回调的优点

1. **灵活性**：
   - 回调允许你在运行时动态地指定要执行的代码，而不是在编译时硬编码。

2. **解耦**：
   - 回调有助于将代码解耦，使得高阶函数和回调函数可以独立开发和测试。

3. **可扩展性**：
   - 通过回调，你可以轻松地扩展高阶函数的行为，而无需修改其内部实现。

### 示例：使用回调函数

下面是一个简单的示例，展示了如何使用回调函数来处理数据：

```cpp
#include <iostream>
#include <vector>
#include <functional>

// 定义一个高阶函数，接受一个数据向量和一个回调函数
void ProcessData(const std::vector<int>& data, const std::function<void(int)>& callback) {
    for (int value : data) {
        callback(value);
    }
}

int main() {
    // 创建一个数据向量
    std::vector<int> data = {1, 2, 3, 4, 5};

    // 使用 lambda 表达式作为回调函数
    ProcessData(data, [](int value) {
        std::cout << "Processed value: " << value << std::endl;
    });

    return 0;
}
```

### 解释

1. **`ProcessData` 函数**:
   - 这个函数接受两个参数：一个数据向量 `data`，以及一个 `std::function<void(int)>` 类型的引用 `callback`。
   - 函数遍历 `data` 向量中的每个元素，并调用 `callback` 函数对象，将当前元素作为参数传递给它。

2. **`main` 函数**:
   - 创建了一个数据向量 `data`，其中包含一些整数。
   - 定义了一个 lambda 表达式作为回调函数，它接受一个 `int` 类型的参数并输出该值。
   - 调用 `ProcessData` 函数，传递 `data` 和 lambda 表达式作为参数。

### 输出

运行上述代码后，输出将是：

```
Processed value: 1
Processed value: 2
Processed value: 3
Processed value: 4
Processed value: 5
```

这表明 `ProcessData` 函数成功地将 lambda 表达式作为回调函数，并将其应用到数据向量中的每个元素。

### 总结

回调是一种强大的编程模式，允许你在运行时动态地指定要执行的代码。通过将函数（或函数对象）作为参数传递给另一个函数，并在特定事件或条件发生时调用这个函数，你可以实现灵活、解耦和可扩展的代码结构。