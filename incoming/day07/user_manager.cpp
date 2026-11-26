/*class user{
    private:
        std::map<std::string, std::string> users;
        std::vector<std::string> name;
    public:
        user();
        ~user();

        bool adduser(std::string& name,std::string& password);
        bool finduser(std::string& name);
        bool removeuser(std::string& name);
        bool edituser(std::string& name,std::string& password);

        void showAllUsers() const;
}
*/
#include "user_manager.h"

#include <algorithm>
#include <iostream>

user::user() {
    std::cout << "open user_manage" << std::endl;
}

user::~user() {
    std::cout << "close user_manage" << std::endl;
}

bool user::adduser(std::string& userName, std::string& password) {
    if (userName.empty()) {
        std::cout << "用户名为空" << std::endl;
        return false;
    }

    auto result = users.emplace(userName, password);

    if (!result.second) {
        std::cout << "用户名已存在" << std::endl;
        return false;
    }

    // 你的头文件中成员变量叫 name，因此这里使用 name
    this->name.push_back(userName);
    return true;
}

bool user::finduser(std::string& userName) {
    auto it = users.find(userName);

    if (it == users.end()) {
        std::cout << "用户名不存在" << std::endl;
        return false;
    }

    std::cout << "用户：" << it->first << std::endl;
    std::cout << "密码：" << it->second << std::endl;

    return true;
}

bool user::removeuser(std::string& userName) {
    auto userIt = users.find(userName);

    if (userIt == users.end()) {
        std::cout << "用户名不存在" << std::endl;
        return false;
    }

    users.erase(userIt);

    auto nameIt = std::find(name.begin(), name.end(), userName);

    if (nameIt != name.end()) {
        name.erase(nameIt);
    }

    std::cout << "删除成功" << std::endl;
    return true;
}

bool user::edituser(std::string& userName, std::string& password) {
    auto it = users.find(userName);

    if (it == users.end()) {
        std::cout << "用户名不存在" << std::endl;
        return false;
    }

    it->second = password;
    std::cout << "修改成功" << std::endl;
    return true;
}

void user::showAllUsers() const {
    if (name.empty()) {
        std::cout << "当前没有用户" << std::endl;
        return;
    }

    for (const auto& userName : name) {
        auto it = users.find(userName);

        if (it != users.end()) {
            std::cout << "用户名：" << it->first
                      << "  密码：" << it->second
                      << std::endl;
        }
    }
}