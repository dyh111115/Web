#include <fcntl.h>
#include <unistd.h>

#include <iostream>

int main()
{
    std::cout << "当前进程 PID: " << getpid() << '\n';

    int fd = open("/etc/passwd", O_RDONLY);

    if (fd == -1)
    {
        std::cerr << "open failed\n";
        return 1;
    }

    std::cout << "打开文件后 fd = " << fd << '\n';

    char buffer[128];
    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);

    if (n > 0)
    {
        buffer[n] = '\0';
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

    close(fd);
    std::cout << "文件已关闭\n";

    return 0;
}
