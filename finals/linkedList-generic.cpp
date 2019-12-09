#include <iostream>

using namespace std;

template <class TYPE> 
class ListOf {
public :
	TYPE data;
	ListOf<TYPE>* next;

	// constructor
	ListOf<TYPE>(TYPE d) {
		data = d;
		next = NULL;
	}

	ListOf<TYPE>* append(TYPE i) {
		ListOf<TYPE>* newItem = new ListOf<TYPE>(i);
		next = newItem;
		return newItem;
	}

	void printList(){
		ListOf<TYPE>* ptr = this; 
		while(ptr != NULL){
			cout << ptr->data << endl;
			ptr = ptr->next;
		} // while
	}
};

void main() {
	ListOf<int>* anchor = new ListOf<int>(5);
	anchor->append(4)->append(9)->append(10);
	anchor->printList();

	cout << endl;

	ListOf<char>* anchor1 = new ListOf<char>('A');
	anchor1->append('D')->append('E')->append('Z');
	anchor1->printList();
}
