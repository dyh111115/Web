// 文件功能：演示用 std::map 保存用户名到密码的映射，并按用户名查询密码。
#include <iostream>
#include <map>    // 提供 std::map 键值对容器。
#include <string> // 提供 std::string 字符串类型。

// 函数功能：程序入口，读取用户名并查询对应密码。
// 调用格式：由操作系统启动，例如 ./user_map_demo
int main()
{
    std::map<std::string, std::string> users;

    // 调用格式：map[键] = 值;
    users["admin"] = "123456";
    users["alice"] = "alice123";
    users["bob"] = "bob123";

    std::string name;
    std::cout << "请输入用户名: ";

    if (!std::getline(std::cin, name)) // 调用格式：getline(cin, string变量)
    {
        std::cerr << "读取失败\n";
        return 1;
    }

    auto it = users.find(name); // 调用格式：map.find(键)，返回迭代器。

    if (it != users.end())
    {
        std::cout << "密码: " << it->second << '\n'; // it->second 是键对应的值。
    }
    else
    {
        std::cout << "用户不存在\n";
    }

    return 0;
}
