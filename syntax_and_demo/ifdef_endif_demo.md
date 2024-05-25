# 预编译指令

```cpp
#ifdef
    ...
#endif

```


---


### 示例demo

首先，假设我们定义了一个宏 `DEBUG`，如果定义了这个宏，我们就会在程序中输出调试信息。否则，我们将不输出这些调试信息。

```cpp
#include <iostream>

// 定义 DEBUG 宏
#define DEBUG

int main() {
    std::cout << "程序开始运行..." << std::endl;

#ifdef DEBUG
    std::cout << "调试信息: 进入main函数" << std::endl;
#else
    std::cout << "DEBUG 没有被定义" << std::endl;
#endif

    // 其他代码
    int a = 5;
    int b = 10;
    int sum = a + b;

#ifdef DEBUG
    std::cout << "调试信息: 计算sum的值: " << sum << std::endl;
#endif

    std::cout << "程序结束运行..." << std::endl;
    return 0;
}
```

在这个示例中：

1. 我们定义了 `DEBUG` 宏。
2. 使用 `#ifdef DEBUG` 检查是否定义了 `DEBUG` 宏。
3. 如果 `DEBUG` 宏被定义了，编译器将包括 `#ifdef` 和 `#endif` 之间的代码。这些代码将输出一些调试信息。
4. 如果 `DEBUG` 宏没有被定义，那么这些调试信息的代码将被编译器忽略。

你可以通过注释或取消注释 `#define DEBUG` 来启用或禁用调试信息的输出。

### 禁用调试信息

如果你想禁用调试信息，只需注释掉或删除 `#define DEBUG`：

```cpp
#include <iostream>

// #define DEBUG

int main() {
    std::cout << "程序开始运行..." << std::endl;

#ifdef DEBUG
    std::cout << "调试信息: 进入main函数" << std::endl;
#endif

    // 其他代码
    int a = 5;
    int b = 10;
    int sum = a + b;

#ifdef DEBUG
    std::cout << "调试信息: 计算sum的值: " << sum << std::endl;
#endif

    std::cout << "程序结束运行..." << std::endl;
    return 0;
}
```

在这种情况下，调试信息将不会被输出。这样，你可以通过简单的宏定义来控制程序的调试信息输出，而无需修改大量代码。
