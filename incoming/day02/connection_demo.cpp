// 文件功能：演示栈对象和堆对象的构造、使用与析构顺序。
#include <iostream>

// 类功能：用对象生命周期模拟一个连接的打开、使用和关闭。
class Connection
{
private:
    int fd_;

public:
    // 函数功能：构造函数，保存 fd 并输出“打开”信息。
    // 调用格式：Connection conn(3); 或 new Connection(4);
    Connection(int fd) : fd_(fd)
    {
        std::cout << "open fd=" << fd_ << '\n';
    }

    // 函数功能：析构函数，输出“关闭”信息。
    // 调用格式：对象离开作用域或 delete 时自动调用，不能手动调用。
    ~Connection()
    {
        std::cout << "close fd=" << fd_ << '\n';
    }

    // 函数功能：显示当前连接保存的 fd。
    // 调用格式：conn.show(); 或 ptr->show();
    void show()
    {
        std::cout << "connection fd=" << fd_ << '\n';
    }
};

// 函数功能：程序入口，分别观察栈对象和堆对象的析构时机。
// 调用格式：由操作系统启动，例如 ./connection_demo
int main()
{
    std::cout << "--- stack ---\n";
    {
        Connection conn(3);     // 栈对象：离开当前作用域时自动析构。
        conn.show();
    }

    std::cout << "--- heap ---\n";
    {
        Connection* ptr = new Connection(4); // 堆对象：需要 delete。
        ptr->show();
        std::cout << "if delete\n";
        delete ptr;            // 调用格式：delete 对象指针;
        std::cout << "--- end ---\n";
    }

    return 0;
}
