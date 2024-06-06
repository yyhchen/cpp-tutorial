#include <iostream>
using namespace std;
#include "test.h"
#include "test1.h"
// using namespace testSpace;
// using namespace test1Space;

void test1();
int test2();
int main() {
    std::cout << "Hello, World!" << std::endl;
    testSpace::test1();     // 包含了头文件就不需要在定义 using namesapce了
    test1Space::test1();
    int a = testSpace::test2();
    int* p = &a;
    cout << p << endl;
    return 0;
}
