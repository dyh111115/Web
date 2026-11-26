// 文件功能：读取三个成绩，计算平均分并判断是否通过。
#include <iostream>

// 函数功能：程序入口，完成成绩输入、平均分计算和结果输出。
// 调用格式：由操作系统启动，例如 ./basics
int main()
{
    int sum = 0;

    // 循环读取三个成绩并累加到 sum。
    for (int i = 1; i <= 3; ++i)
    {
        int score = 0;
        std::cout << "请输入第 " << i << " 个成绩: ";
        std::cin >> score;
        sum += score;
    }

    // 使用 3.0 保证执行浮点除法，而不是整数除法。
    double average = sum / 3.0;

    // 根据平均分输出是否通过。
    if (average >= 60)
    {
        std::cout << "通过，平均分：" << average << '\n';
    }
    else
    {
        std::cout << "未通过，平均分：" << average << '\n';
    }

    return 0;
}
