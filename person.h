#pragma once

#include <string>
using std::string;

class Person{
	string _name;
	size_t _age;
public:
	Person(const string&, size_t);
	void IncreaseAge();
	string ToString()const;
};
