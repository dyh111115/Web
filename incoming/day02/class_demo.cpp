// 文件功能：演示类的封装、构造函数、成员函数、析构函数以及对象访问方式。
#include <iostream>
#include <string> // 提供 std::string 字符串类型。

// 类功能：保存用户名，并提供修改和打印用户信息的方法。
class User
{
private:
    std::string name;

public:
    // 函数功能：构造函数，用传入的字符串初始化用户名。
    // 调用格式：User user("Alice"); 或 new User("Alice");
    User(const std::string& name)
    {
        this->name = name;
    }

    // 函数功能：修改用户名。
    // 调用格式：user.rename("Bob");
    void rename(const std::string& name)
    {
        this->name = name;
    }

    // 函数功能：打印当前用户名。
    // 调用格式：user.print();
    void print() const
    {
        std::cout << "user: " << name << '\n';
    }

    // 函数功能：析构函数，在对象销毁时打印提示。
    // 调用格式：对象离开作用域或 delete 时自动调用，不能手动调用。
    ~User()
    {
        std::cout << "delete " << name << '\n';
    }
};

// 函数功能：程序入口，演示栈对象、成员函数、指针访问和自动析构。
// 调用格式：由操作系统启动，例如 ./class_demo
int main()
{
    User user("Alice");
    user.print();            // 调用格式：对象.成员函数()

    user.rename("Bob");      // 调用格式：对象.成员函数(参数)
    user.print();

    User* ptr = &user;
    ptr->print();            // 调用格式：对象指针->成员函数()

    return 0;
}
