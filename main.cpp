#include "person.h"
#include <iostream>
using std::cout;
using std::endl;


int main(){
	Person p("Jane", 14);
	cout << p.ToString() << endl;
	p.IncreaseAge();
	cout << p.ToString() << endl;
	return 0;
}
