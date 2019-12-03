#include <iostream>

class Object {
public:
	static int counter; // question 5
	Object() {		    // question 5
		counter++;	    // question 5
	}
};
int Object::counter = 0; // question 5

class Character : public Object {
protected: // question 6 (part 1)
	char ch; // question 2
public:
	Character() {} // question 7
	Character( char c ) { // question 2
		ch = c;
	}
	Character operator+( Character c ) // question 3
	{
		return Character((char)((int)ch + (int)c.ch) % 25  + 65);
	}

	// question 6 (part 2)
	char get() {
		return ch;
	}

	// question 6 (part 2)
	void set( char c ) { // setter avoids characters greater than 127
		Character::ch = (c < 128) ? c : 0;
		//this -> ch 도 가능
	}
};
class Digit : public Character { // question 4
public:
	Digit( char c ) : Character(c) {} // constructor
	Digit operator+( Digit digit )
	{
		return Digit( ((ch - '0') + (digit.ch - '0')) % 10 + '0' );
	}
};
class Letter : public Character {
public:
};
class Vowel : public Letter {
public:
};
class Consonant : public Letter {
public:
};

int main() {
	// question 7
	// Object cObj1();
	// Object cObj2();
	Character cObj3('B');
	Character cObj4('C');
	Digit cObj5( '1' );
	Digit cObj6( '4' );
	Letter cObj7;
	Letter cObj8;
	Vowel cObj9;
	Vowel cObj10;
	Consonant cObj11;
	Consonant cObj12;
	std::cout << Object::counter << std::endl;

    return 0;
} // function
