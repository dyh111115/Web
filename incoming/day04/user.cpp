#include "user.h"

#include <iostream>

UserManager::UserManager()
{
    users_["admin"] = "123456";
    users_["alice"] = "alice123";
}

bool UserManager::addUser(const std::string& name,
                          const std::string& password)
{
    if (name.empty() || password.empty())
    {
        return false;
    }

    if (users_.find(name) != users_.end())
    {
        return false;
    }

    users_[name] = password;
    return true;
}

bool UserManager::checkPassword(const std::string& name,
                                const std::string& password) const
{
    auto it = users_.find(name);

    if (it == users_.end())
    {
        return false;
    }

    return it->second == password;
}

void UserManager::printAll() const
{
    for (const auto& item : users_)
    {
        std::cout << item.first << " -> " << item.second << '\n';
    }
}
