#include "user_manager.h"

#include <iostream>
#include <limits>
#include <string>

int main() {
    user manager;

    int choice = -1;
    std::string name;
    std::string password;

    while (true) {
        std::cout << "\n===== 用户管理系统 =====" << std::endl;
        std::cout << "1. 添加用户" << std::endl;
        std::cout << "2. 查询用户" << std::endl;
        std::cout << "3. 删除用户" << std::endl;
        std::cout << "4. 修改密码" << std::endl;
        std::cout << "5. 显示所有用户" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择：";

        if (!(std::cin >> choice)) {
            std::cout << "输入格式错误，请输入数字。" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "请输入用户名：";
            std::cin >> name;
            std::cout << "请输入密码：";
            std::cin >> password;

            if (manager.adduser(name, password)) {
                std::cout << "添加成功" << std::endl;
            }
            break;

        case 2:
            std::cout << "请输入要查询的用户名：";
            std::cin >> name;
            manager.finduser(name);
            break;

        case 3:
            std::cout << "请输入要删除的用户名：";
            std::cin >> name;
            manager.removeuser(name);
            break;

        case 4:
            std::cout << "请输入要修改的用户名：";
            std::cin >> name;
            std::cout << "请输入新密码：";
            std::cin >> password;
            manager.edituser(name, password);
            break;

        case 5:
            manager.showAllUsers();
            break;

        case 0:
            std::cout << "退出程序。" << std::endl;
            return 0;

        default:
            std::cout << "无效选项，请重新选择。" << std::endl;
            break;
        }
    }
}