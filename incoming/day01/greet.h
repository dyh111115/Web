// 文件功能：声明问候程序的函数接口，供 main.cpp 和 greet.cpp 共同使用。
#ifndef GREET_H
#define GREET_H

#include <string> // 提供 std::string 字符串类型。

// 函数功能：读取一整行用户名，空输入时重新提示。
// 调用格式：std::string name = readName();
std::string readName();

// 函数功能：根据用户名生成问候语。
// 调用格式：std::string msg = buildGreeting(name);
std::string buildGreeting(const std::string& name);

// 函数功能：输出问候语。
// 调用格式：printGreeting(message);
void printGreeting(const std::string& message);

#endif // GREET_H
