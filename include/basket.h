
#pragma once

#include <map>

class Basket
{
public:
	void add();
	void remove();
	void show();
private:
	std::map<int,int> basket;

};



