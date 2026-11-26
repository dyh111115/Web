// 文件功能：实现 user.h 中声明的 UserManager 成员函数。
#include "user.h" // 引入 UserManager 的接口声明。

#include <iostream>

// 函数功能：构造函数，创建对象时添加两个默认用户。
// 调用格式：UserManager users;
UserManager::UserManager()
{
    users_["admin"] = "123456";
    users_["alice"] = "alice123";
}

// 函数功能：添加用户；空用户名、空密码或用户名已存在时返回 false。
// 调用格式：users.addUser(name, password);
bool UserManager::addUser(const std::string& name,
                          const std::string& password)
{
    if (name.empty() || password.empty())
    {
        return false;
    }

    if (users_.find(name) != users_.end())
    {
        return false;
    }

    users_[name] = password;
    return true;
}

// 函数功能：检查用户名是否存在，并验证密码是否正确。
// 调用格式：users.checkPassword(name, password);
bool UserManager::checkPassword(const std::string& name,
                                const std::string& password) const
{
    auto it = users_.find(name); // 调用格式：map.find(键)

    if (it == users_.end())
    {
        return false;
    }

    return it->second == password;
}

// 函数功能：遍历并输出所有用户名和密码。
// 调用格式：users.printAll();
void UserManager::printAll() const
{
    for (const auto& item : users_)
    {
        std::cout << item.first << " -> " << item.second << '\n';
    }
}
