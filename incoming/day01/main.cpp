// 文件功能：问候程序入口，调用读取、生成和输出问候语的函数。
#include "greet.h" // 引入 readName、buildGreeting、printGreeting 的声明。

#include <iostream>
#include <string> // 提供 std::string。

// 函数功能：程序入口，读取用户名并输出问候语。
// 调用格式：由操作系统启动，例如 ./greet
int main()
{
    std::string name = readName(); // 调用格式：readName()

    if (name.empty())
    {
        std::cerr << "没有读取到用户名。\n";
        return 1;
    }

    std::string message = buildGreeting(name); // 调用格式：buildGreeting(name)
    printGreeting(message);                    // 调用格式：printGreeting(message)

    return 0;
}
