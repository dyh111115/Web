// 文件功能：创建两个线程共同累加共享变量，并用互斥锁避免数据竞争。
#include <iostream>
#include <mutex>  // 提供 std::mutex 和 std::lock_guard。
#include <thread> // 提供 std::thread 线程类型。

int counter = 0;                  // 两个线程共享的计数器。
std::mutex counter_mutex;         // 保护 counter 的互斥锁。

// 函数功能：把共享计数器增加 times 次。
// 调用格式：std::thread t(add, 500000); 或 add(500000);
void add(int times)
{
    for (int i = 0; i < times; ++i)
    {
        // 调用格式：std::lock_guard<std::mutex> lock(互斥锁变量);
        std::lock_guard<std::mutex> lock(counter_mutex);
        ++counter;
    }
}

// 函数功能：程序入口，创建两个线程并等待它们结束。
// 调用格式：由操作系统启动，例如 ./thread_demo
int main()
{
    // 调用格式：std::thread 线程变量(函数名, 参数列表);
    std::thread t1(add, 500000);
    std::thread t2(add, 500000);

    t1.join(); // 调用格式：线程.join()，等待线程结束。
    t2.join();

    std::cout << "counter = " << counter << '\n';

    return 0;
}
