// 文件功能：用户管理程序入口，读取命令并调用 UserManager 的接口。
#include "user.h" // 引入 UserManager 的公共接口声明。

#include <iostream>
#include <string> // 提供 std::string 保存命令、用户名和密码。

// 函数功能：程序入口，循环处理 add、check、list、quit 命令。
// 调用格式：由操作系统启动，例如 ./user_app
int main()
{
    UserManager users; // 调用构造函数：UserManager users;
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

            // 调用格式：users.addUser(name, password)
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

            // 调用格式：users.checkPassword(name, password)
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
            users.printAll(); // 调用格式：users.printAll();
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
