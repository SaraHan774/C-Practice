#include <iostream>
using namespace std;

template <class TP> 
TP max_value(TP d1, TP d2) { 
	return (d1 > d2) ? d1 : d2;
} 

template <> 
char* max_value(char* d1, char* d2) { 
	return (strcmp(d1,d2)>0) ? d1 : d2; 
} 

void main() {
	cout << max_value(4, 12) << endl;
	cout << max_value(2.0, 5.0) << endl;
	cout << max_value('A', 'C') << endl;
	cout << max_value("cat", "mouse") << endl;
}