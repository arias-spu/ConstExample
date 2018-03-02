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
string Person::GetName(){
	return _name;
}
string Person::ToString()const{
	stringstream retVal;
	retVal << setw(10) << GetName() << setw(6) << _age; // Compilation error on the call to GetName, see below
	// Will not compile because of this line
	IncreaseAge();	// since this method is not const, there is no guarantee
			// that it will not change this, and ToString IS const
			// so the compiler will not allow the call of a non-const method
			// inside a const method
			// Sometimes you'd try to call a Get (Accessor), but you MUST put
			// the const modifier to the method (the const at the end)
			// so the compiler knows for sure that that method call doesn't
			// change this
			// If you comment the IncreaseAge line, that clearly changes this
			// the program still doesn't compile, because of the call of 
			// the method GetName (see above), that even when it does not change this
			// is not marked as const.
			// TO FIX THIS PROGRAM:
			// 	* Delete the line that calls IncreaseAge()
			//	* Add the const modifier to the method GetName both
			//	  in the header file (.h) and in the definitions file (.cpp)
	return retVal.str();
}
