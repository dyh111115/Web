#include <iostream>

int main(){
    int value = 10;
    int& ref = value;  //引用
    int* ptr = &value; //指针
    std::cout << "初始值: "
              << value << ' ' << ref << ' ' << *ptr << '\n';

    ref = 20;
    std::cout << "修改引用后: " << value << '\n';

    *ptr = 30;
    std::cout << "修改指针后: " << ref << '\n';

    int* empty = nullptr;
    if (empty == nullptr)
    {
        std::cout << "empty pointer\n";
    }

    return 0;
}