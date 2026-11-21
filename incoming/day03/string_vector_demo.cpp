#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string text = "hello";
    text += " world";

    std::cout << "text=" << text << '\n';
    std::cout << "size=" << text.size() << '\n';

    std::size_t pos = text.find("world");
    if (pos != std::string::npos)
    {
        std::cout << "find world at " << pos << '\n';
    }

    std::vector<std::string> paths;
    paths.push_back("/");
    paths.push_back("/index.html");
    paths.push_back("/favicon.ico");

    std::cout << "paths size=" << paths.size() << '\n';

    for (const std::string& path : paths)
    {
        std::cout << path << '\n';
    }
    paths.pop_back();
    std::cout << "after pop size=" << paths.size() << '\n';

    for (const std::string& path : paths)
    {
        std::cout << path << '\n';
    }

    return 0;
}