#include <iostream>

int main()
{
    int sum = 0;

    for (int i = 1; i <= 3; ++i)
    {
        int score = 0;
        std::cout << "请输入第 " << i << " 个成绩: ";
        std::cin >> score;
        sum += score;
    }

    double average = sum / 3.0;

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