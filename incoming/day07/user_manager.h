#include<iostream>
#include <map>
#include <string>
#include <vector>

class user{
    private:
        std::map<std::string, std::string> users;
        std::vector<std::string> name;
    public:
        user();
        ~user();

        bool adduser(std::string& name,std::string& password);
        bool finduser(std::string& name);
        bool removeuser(std::string& name);
        bool edituser(std::string& name,std::string& password);

        void showAllUsers() const;
};