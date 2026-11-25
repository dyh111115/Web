#include <sys/wait.h>
#include <unistd.h>

#include <iostream>

int main()
{
    int value = 100;

    pid_t pid = fork();

    if (pid == -1)
    {
        std::cerr << "fork failed\n";
        return 1;
    }

    if (pid == 0)
    {
        value = 200;
        std::cout << "子进程: pid=" << getpid()
                  << ", ppid=" << getppid()
                  << ", value=" << value << std::endl;
        _exit(0);
    }

    int status = 0;
    waitpid(pid, &status, 0);

    std::cout << "父进程: pid=" << getpid()
              << ", child pid=" << pid
              << ", value=" << value << std::endl;

    return 0;
}
