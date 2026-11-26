// 文件功能：创建子进程，并观察父子进程内存和 PID。
#include <sys/wait.h> // 提供 waitpid()，用于等待和回收子进程。
#include <unistd.h>   // 提供 fork()、getpid()、getppid()、_exit()。

#include <iostream>

// 函数功能：程序入口，创建子进程并比较父子进程中的变量值。
// 调用格式：由操作系统启动，例如 ./fork_demo
int main()
{
    int value = 100;

    pid_t pid = fork(); // 调用格式：pid_t pid = fork();

    if (pid == -1)
    {
        std::cerr << "fork failed\n";
        return 1;
    }

    if (pid == 0)
    {
        // 子进程分支：修改变量不会影响父进程。
        value = 200;
        std::cout << "子进程: pid=" << getpid()
                  << ", ppid=" << getppid()
                  << ", value=" << value << std::endl;
        _exit(0); // 调用格式：_exit(退出码)，直接结束当前子进程。
    }

    int status = 0;
    // 调用格式：waitpid(子进程PID, &状态变量, 选项)
    waitpid(pid, &status, 0);

    std::cout << "父进程: pid=" << getpid()
              << ", child pid=" << pid
              << ", value=" << value << std::endl;

    return 0;
}
