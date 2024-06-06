# namespace 使用 demo

[参考博客](https://www.cnblogs.com/zjuhaohaoxuexi/p/16470576.html)

---

## C++ 引入命名空间是为了避免合作开发项目时产生命名冲突


这里是为了在 `main.cpp` 中使用不同 `.cpp` 文件中的 **同名** 函数，因此通过命名空间来区分

<br>
<br>
<br>

## 目录结构
```
project/
├── CMakeLists.txt
├── main.cpp
├── test.cpp
└── test1.cpp

```

如果需要使用 **CMake** 编译，那么 **CMakeLists.txt** 如下：

```cpp
cmake_minimum_required(VERSION 3.28)
project(demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo main.cpp
        test.cpp
        test1.cpp
        test.h
        test1.h
)
```
