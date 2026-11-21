#include <iostream>
#include <string>

class User
{
    private:
    std::string name;
    public:
        User(const std::string &name){
            this->name = name;
        }
        void rename(const std::string& name){
            this->name = name;
        }
        void print() const{
            std::cout << "user: " << name << '\n';
        }
        ~User(){
            std::cout << "delete " << name << '\n';
        }
};

int main()
{
    User user("Alice");
    user.print();

    user.rename("Bob");
    user.print();

    User* ptr = &user;
    ptr->print();

    return 0;
}