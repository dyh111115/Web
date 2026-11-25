#ifndef USER_H
#define USER_H

#include <map>
#include <string>

class UserManager
{
public:
    UserManager();

    bool addUser(const std::string& name,
                 const std::string& password);

    bool checkPassword(const std::string& name,
                       const std::string& password) const;

    void printAll() const;

private:
    std::map<std::string, std::string> users_;
};

#endif
