// 文件功能：演示读取文件时对 EINTR 错误进行重试。
#include <fcntl.h>  // 提供 open() 和 O_RDONLY 打开标志。
#include <unistd.h> // 提供 read() 和 close()。

#include <cerrno> // 提供 errno、EINTR 错误码。
#include <cstdio> // 提供 std::perror()。
#include <iostream>

// 函数功能：程序入口，打开文件并读取一段内容。
// 调用格式：由操作系统启动，例如 ./retry_demo
int main()
{
    int fd = open("/etc/passwd", O_RDONLY); // 调用格式：open(路径, 打开标志)
    if (fd == -1)
    {
        std::perror("open"); // 调用格式：perror(错误前缀)
        return 1;
    }

    char buffer[256];
    ssize_t n = -1;

    do
    {
        // 调用格式：read(fd, 缓冲区, 最大字节数)
        n = read(fd, buffer, sizeof(buffer));
    }
    while (n == -1 && errno == EINTR); // 被信号中断时重新读取。

    if (n == -1)
    {
        std::perror("read");
        close(fd);
        return 1;
    }

    if (n == 0)
    {
        std::cout << "end of file\n";
    }
    else
    {
        std::cout << "read " << n << " bytes\n";
    }

    close(fd); // 调用格式：close(fd)
    return 0;
}
