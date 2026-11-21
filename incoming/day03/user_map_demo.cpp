#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, std::string> users;

    users["admin"] = "123456";
    users["alice"] = "alice123";
    users["bob"] = "bob123";
    
    std::string name;
    std::cout << "请输入用户名: ";

    if (!std::getline(std::cin , name)){
        std::cerr << "读取失败\n";
        return 1;
    }

     auto it = users.find(name);


    if (it != users.end())
    {
        std::cout << "密码: " << it->second << '\n';
    }
    else
    {
        std::cout << "用户不存在\n";
    }

    return 0;
}