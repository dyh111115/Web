// 文件功能：创建 Socket 并绑定 9006 端口，用于观察端口占用错误。
#include <arpa/inet.h>  // 提供 IPv4 地址结构和 htons() 端口字节序转换。
#include <sys/socket.h> // 提供 socket()、bind() 和 AF_INET、SOCK_STREAM。
#include <unistd.h>     // 提供 close() 和 sleep()。

#include <cstdio> // 提供 std::perror() 输出系统错误信息。
#include <iostream>

// 函数功能：程序入口，绑定端口后保持运行 60 秒。
// 调用格式：由操作系统启动，例如 ./bind_port_demo
int main()
{
    // 调用格式：socket(地址族, Socket类型, 协议)，成功返回 fd，失败返回 -1。
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        std::perror("socket"); // 调用格式：perror(错误前缀)
        return 1;
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9006); // 调用格式：htons(主机字节序端口)

    // 调用格式：bind(fd, (sockaddr*)&地址结构, sizeof(地址结构))
    if (bind(fd,
             reinterpret_cast<sockaddr*>(&address),
             sizeof(address)) == -1)
    {
        std::perror("bind");
        close(fd);
        return 1;
    }

    std::cout << "bind success on port 9006\n";
    std::cout << "keep the process running...\n";

    sleep(60); // 调用格式：sleep(秒数)，让进程保持运行。

    close(fd); // 调用格式：close(fd)，释放 Socket fd。
    return 0;
}
