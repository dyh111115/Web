// 文件功能：实现 greet.h 中声明的用户名读取和问候函数。
#include "greet.h" // 引入本模块的函数声明，确保声明与定义一致。

#include <iostream>
#include <string> // 提供 std::string 和 std::getline。

// 函数功能：读取一整行用户名，空输入时重新提示，输入失败时返回空字符串。
// 调用格式：std::string name = readName();
std::string readName()
{
    std::string name;

    while (true)
    {
        std::cout << "请输入用户名: ";

        // getline 可以读取包含空格的整行内容。
        if (!std::getline(std::cin, name))
        {
            return "";
        }

        if (!name.empty())
        {
            return name;
        }

        std::cout << "用户名不能为空，请重新输入。\n";
    }
}

// 函数功能：把用户名拼接到 "Hello, " 后面。
// 调用格式：std::string msg = buildGreeting(name);
std::string buildGreeting(const std::string& name)
{
    return "Hello, " + name;
}

// 函数功能：把问候语输出到标准输出。
// 调用格式：printGreeting(message);
void printGreeting(const std::string& message)
{
    std::cout << message << '\n';
}
