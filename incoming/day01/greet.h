#ifndef GREET_H
#define GREET_H

#include <string>

std::string readName();
std::string buildGreeting(const std::string& name);
void printGreeting(const std::string& message);

#endif