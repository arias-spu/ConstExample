#include "person.h"

#include <string>
#include <sstream>
#include <iomanip>
using std::string;
using std::stringstream;
using std::setw;

Person::Person(const string& name, size_t age): _name(name), _age(age){
}
void Person::IncreaseAge(){
	_age++;
}
string Person::ToString()const{
	stringstream retVal;
	retVal << setw(10) << _name << setw(6) << _age;
	return retVal.str();
}
