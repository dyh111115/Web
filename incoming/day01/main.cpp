#include "greet.h"

#include <iostream>
#include <string>

int main()
{
    std::string name = readName();

    if (name.empty())
    {
        std::cerr << "没有读取到用户名。\n";
        return 1;
    }

    std::string message = buildGreeting(name);
    printGreeting(message);

    return 0;
}