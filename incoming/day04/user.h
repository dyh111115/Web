// 文件功能：声明 UserManager 的公共接口，供 main.cpp 调用、user.cpp 实现。
#ifndef USER_H
#define USER_H

#include <map>    // 提供 std::map 保存用户名到密码的映射。
#include <string> // 提供 std::string 用户名和密码类型。

// 类功能：管理一组用户名和密码，并提供添加、验证和显示功能。
class UserManager
{
public:
    // 函数功能：构造函数，初始化默认用户。
    // 调用格式：UserManager users;
    UserManager();

    // 函数功能：添加用户，空输入或用户名重复时返回 false。
    // 调用格式：bool ok = users.addUser(name, password);
    bool addUser(const std::string& name,
                 const std::string& password);

    // 函数功能：检查用户名和密码是否匹配。
    // 调用格式：bool ok = users.checkPassword(name, password);
    bool checkPassword(const std::string& name,
                       const std::string& password) const;

    // 函数功能：输出全部用户名和密码。
    // 调用格式：users.printAll();
    void printAll() const;

private:
    std::map<std::string, std::string> users_;
};

#endif // USER_H
