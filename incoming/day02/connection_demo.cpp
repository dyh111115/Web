#include <iostream>

class Connection{
    private:
        int fd_;
    public:
        Connection(int fd) : fd_(fd){
            std::cout << "open fd=" << fd_ << '\n';
        }   
        ~Connection(){
        std::cout << "close fd=" << fd_ << '\n';
        }
        void show(){
            std::cout << "connection fd=" << fd_ << '\n';
        }
};

int main(){
    std::cout << "--- stack ---\n";
    {
    Connection conn(3);
    conn.show();
    }
    std::cout << "--- heap ---\n";
    {
    Connection* ptr = new Connection(4);
    ptr->show();
    std::cout << "if delete\n";
    delete ptr;
    std::cout << "--- end ---\n";
    return 0;
}
}