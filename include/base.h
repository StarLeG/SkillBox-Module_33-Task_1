#pragma once

#include <map>
#include <string>

class Base
{

public:
    Base(/* args */);
    ~Base();

    void add(std::string article, int amount);
    void remove(std::string article, int amount);
    void show() const;

protected:
    std::map<std::string, int> base;
};
