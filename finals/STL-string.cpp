#include <string>
#include <iostream>
using namespace std;

void main() {
	string s0;
	string s1 = "cat";
	string s2 = "alogue";

	cout << s1 << s2 << endl; // Output

	s0 = s1 + s2; // Catenation

	int at = s0.find("log"); // find substring

	cout << s0.substr(at,3) << endl;

	s1.replace(2,1,"nary"); // substing replacement

	char c = s2[4]; // access to single characters

	s2[4] = 'q';

	char * ch_str = "Char based text";
	string s3 = string(ch_str); // constructor 

	cout << s3 << endl;

	const char * text = s3.data(); // get the data-part of string s3

	cout << s3 << endl;
}