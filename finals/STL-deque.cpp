#include <iostream>
#include <deque>
#include <string>

using namespace std;

void main() {

	deque<string> names;

	names.push_back("Kim");
	names.push_back("Park");
	names.push_back("Lee");
	names.push_back("Gang");

	for (unsigned int i = 0; i < names.size(); i++)
		// will throw exception if no element at i
		cout << i << names.at(i) << endl;

	names[2] = "Walter";

	for (unsigned int i = 0; i < names.size(); i++) {
		string s = names[i]; // expensive
		cout << i << s << endl;
	}

	names.pop_front();

	for (unsigned int i = 0; i < names.size(); i++)
		cout << i << names[i] << endl;
}