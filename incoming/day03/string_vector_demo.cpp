// 文件功能：演示 std::string 的拼接、查找，以及 std::vector 的增删和遍历。
#include <iostream>
#include <string> // 提供 std::string 字符串类型。
#include <vector> // 提供 std::vector 动态数组容器。

// 函数功能：程序入口，演示 string 和 vector 的常用操作。
// 调用格式：由操作系统启动，例如 ./string_vector_demo
int main()
{
    std::string text = "hello";
    text += " world"; // 调用格式：字符串 += 追加内容

    std::cout << "text=" << text << '\n';
    std::cout << "size=" << text.size() << '\n'; // 调用格式：字符串.size()

    std::size_t pos = text.find("world"); // 调用格式：字符串.find(子串)
    if (pos != std::string::npos)
    {
        std::cout << "find world at " << pos << '\n';
    }

    std::vector<std::string> paths;
    paths.push_back("/");              // 调用格式：vector.push_back(元素)
    paths.push_back("/index.html");
    paths.push_back("/favicon.ico");

    std::cout << "paths size=" << paths.size() << '\n'; // 调用格式：vector.size()

    for (const std::string& path : paths)
    {
        std::cout << path << '\n';
    }

    paths.pop_back(); // 调用格式：vector.pop_back()
    std::cout << "after pop size=" << paths.size() << '\n';

    for (const std::string& path : paths)
    {
        std::cout << path << '\n';
    }

    return 0;
}
