// 文件功能：演示指针和引用如何访问、修改同一个变量。
#include <iostream>

// 函数功能：程序入口，比较指针和引用的读写方式，并演示空指针判断。
// 调用格式：由操作系统启动，例如 ./pointer_reference_demo
int main()
{
    int value = 10;
    int& ref = value;   // 调用格式：类型& 引用名 = 已有变量;
    int* ptr = &value;  // 调用格式：类型* 指针名 = &已有变量;

    std::cout << "初始值: "
              << value << ' ' << ref << ' ' << *ptr << '\n';

    ref = 20;           // 通过引用修改原变量。
    std::cout << "修改引用后: " << value << '\n';

    *ptr = 30;          // 调用格式：*指针 = 新值; 通过指针修改原变量。
    std::cout << "修改指针后: " << ref << '\n';

    int* empty = nullptr; // 空指针表示当前不指向任何对象。
    if (empty == nullptr)
    {
        std::cout << "empty pointer\n";
    }

    return 0;
}
