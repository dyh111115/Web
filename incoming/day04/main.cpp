#include "user.h"

#include <iostream>
#include <string>

int main()
{
    UserManager users;
    std::string command;

    while (true)
    {
        std::cout << "\n命令(add/check/list/quit): ";
        if (!(std::cin >> command))
        {
            break;
        }

        if (command == "add")
        {
            std::string name;
            std::string password;

            std::cout << "用户名: ";
            std::cin >> name;
            std::cout << "密码: ";
            std::cin >> password;

            if (users.addUser(name, password))
            {
                std::cout << "添加成功\n";
            }
            else
            {
                std::cout << "添加失败：用户已存在或输入为空\n";
            }
        }
        else if (command == "check")
        {
            std::string name;
            std::string password;

            std::cout << "用户名: ";
            std::cin >> name;
            std::cout << "密码: ";
            std::cin >> password;

            if (users.checkPassword(name, password))
            {
                std::cout << "密码正确\n";
            }
            else
            {
                std::cout << "用户不存在或密码错误\n";
            }
        }
        else if (command == "list")
        {
            users.printAll();
        }
        else if (command == "quit")
        {
            break;
        }
        else
        {
            std::cout << "未知命令\n";
        }
    }

    return 0;
}
