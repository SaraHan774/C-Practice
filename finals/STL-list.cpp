#include <iostream>
#include <list>
#include <string>

using namespace std;

void main() {
	list<string> names;

	names.push_back("Kim");
	names.push_back("Park");
	names.push_back("Lee");
	names.push_back("Gang");
	
	// iterator based list output
	for (list<string>::iterator  ai = names.begin(); 
		                         ai != names.end(); 
								 ai++)
		cout << *ai << endl;

	cout << endl;
	names.reverse(); // we reverse the list

	for (list<string>::iterator  ai = names.begin(); 
		                         ai != names.end(); 
								 ai++)
		cout << *ai << endl;

}