// 文件功能：演示 RAII，通过对象析构自动关闭文件描述符。
#include <fcntl.h>  // 提供 open() 和 O_RDONLY 等打开标志。
#include <unistd.h> // 提供 close() 等 POSIX 系统调用。

#include <iostream>
#include <string> // 提供 std::string 文件路径类型。

// 类功能：接管一个文件描述符，并在对象销毁时自动关闭它。
class FdGuard
{
public:
    // 函数功能：构造函数打开文件，并把 fd 保存到成员变量。
    // 调用格式：FdGuard file("/etc/passwd");
    FdGuard(const std::string& path)
    {
        fd_ = open(path.c_str(), O_RDONLY); // 调用格式：open(路径, 打开标志)
        if (fd_ == -1)
        {
            std::cerr << "open failed: " << path << '\n';
        }
        else
        {
            std::cout << "open fd=" << fd_ << '\n';
        }
    }

    // 函数功能：析构函数在对象销毁时自动关闭有效 fd。
    // 调用格式：对象离开作用域时自动调用，不能手动调用。
    ~FdGuard()
    {
        if (fd_ != -1)
        {
            std::cout << "close fd=" << fd_ << '\n';
            close(fd_); // 调用格式：close(fd)
        }
    }

    // 函数功能：返回内部保存的文件描述符。
    // 调用格式：int fd = file.get();
    int get() const
    {
        return fd_;
    }

private:
    int fd_;
};

// 函数功能：程序入口，创建 FdGuard 并观察自动关闭文件的过程。
// 调用格式：由操作系统启动，例如 ./fd_guard_demo
int main()
{
    FdGuard file("/etc/passwd"); // 构造对象时自动 open。

    if (file.get() != -1) // 调用格式：对象.get()
    {
        std::cout << "resource is in use\n";
    }

    return 0; // main 结束时 file 析构，自动 close。
}
