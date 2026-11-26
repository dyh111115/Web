// 文件功能：打开文件、读取内容，并观察文件描述符和进程 PID。
#include <fcntl.h>  // 提供 open()、O_RDONLY 等文件打开接口。
#include <unistd.h> // 提供 getpid()、read()、close() 等 POSIX 接口。

#include <iostream>

// 函数功能：程序入口，打开 /etc/passwd，读取一段内容并关闭 fd。
// 调用格式：由操作系统启动，例如 ./fd_demo
int main()
{
    std::cout << "当前进程 PID: " << getpid() << '\n'; // 调用格式：getpid()

    int fd = open("/etc/passwd", O_RDONLY); // 调用格式：open(路径, 打开标志)
    if (fd == -1)
    {
        std::cerr << "open failed\n";
        return 1;
    }

    std::cout << "打开文件后 fd = " << fd << '\n';

    char buffer[128];
    // 调用格式：read(fd, 缓冲区, 最大字节数)，返回实际读取字节数。
    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);

    if (n > 0)
    {
        buffer[n] = '\0'; // 为 C 风格字符串补充结束符。
        std::cout << "读取内容:\n" << buffer << '\n';
    }
    else if (n == 0)
    {
        std::cout << "文件为空或已到末尾\n";
    }
    else
    {
        std::cerr << "read failed\n";
    }

    close(fd); // 调用格式：close(fd)
    std::cout << "文件已关闭\n";

    return 0;
}
