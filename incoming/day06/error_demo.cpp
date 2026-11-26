// 文件功能：演示系统调用失败后如何获取并输出 errno。
#include <fcntl.h>  // 提供 open() 和 O_RDONLY 打开标志。
#include <unistd.h> // 提供 close()。

#include <cerrno>   // 提供 errno 和 ENOENT 等错误码。
#include <cstdio>   // 提供 std::perror()。
#include <cstring>  // 提供 std::strerror()。
#include <iostream>

// 函数功能：程序入口，尝试打开不存在的文件并输出错误原因。
// 调用格式：由操作系统启动，例如 ./error_demo
int main()
{
    const char* path = "/tmp/this_file_does_not_exist_12345.txt";

    int fd = open(path, O_RDONLY); // 调用格式：open(路径, 打开标志)
    if (fd == -1)
    {
        int error_code = errno; // 保存错误码，避免后续调用覆盖 errno。

        std::cerr << "open failed\n";
        std::cerr << "errno = " << error_code << '\n';
        std::cerr << "strerror: "
                  << std::strerror(error_code) << '\n'; // 调用格式：strerror(errno)

        std::perror("open"); // 调用格式：perror(错误前缀)
        return 1;
    }

    std::cout << "open success, fd=" << fd << '\n';
    close(fd); // 调用格式：close(fd)

    return 0;
}
