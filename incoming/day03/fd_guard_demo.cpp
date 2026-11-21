#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <string>

class FdGuard
{
public:
    FdGuard(const std::string& path)
    {
        fd_ = open(path.c_str(), O_RDONLY);

        if (fd_ == -1)
        {
            std::cerr << "open failed: " << path << '\n';
        }
        else
        {
            std::cout << "open fd=" << fd_ << '\n';
        }
    }

    ~FdGuard()
    {
        if (fd_ != -1)
        {
            std::cout << "close fd=" << fd_ << '\n';
            close(fd_);
        }
    }

    int get() const
    {
        return fd_;
    }

private:
    int fd_;
};

int main()
{
    FdGuard file("/etc/passwd");

    if (file.get() != -1)
    {
        std::cout << "resource is in use\n";
    }

    return 0;
}