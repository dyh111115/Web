#include <iostream>
#include <mutex>
#include <thread>

int counter = 0;
std::mutex counter_mutex;

void add(int times)
{
    for (int i = 0; i < times; ++i)
    {
        std::lock_guard<std::mutex> lock(counter_mutex);
        ++counter;
    }
}

int main()
{
    std::thread t1(add, 500000);
    std::thread t2(add, 500000);

    t1.join();
    t2.join();

    std::cout << "counter = " << counter << '\n';

    return 0;
}
