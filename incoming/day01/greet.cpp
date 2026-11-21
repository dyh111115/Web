#include "greet.h"

#include <iostream>
#include <string>

std::string readName()
{
    std::string name;

    while (true)
    {
        std::cout << "请输入用户名: ";

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

std::string buildGreeting(const std::string& name)
{
    return "Hello, " + name;
}

void printGreeting(const std::string& message)
{
    std::cout << message << '\n';
}