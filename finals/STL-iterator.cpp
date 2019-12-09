#include <iostream>
#include <deque>

using namespace std;

void main() {

	deque<string> names;

	names.push_back("Kim");
	names.push_back("Lee");
	names.push_back("Gang");
	names.push_back("Park");

	deque<string>::iterator next = names.begin();
	deque<string>::iterator last = names.end();

	for (; next != last; next++)
		cout << next->data() << endl;
}