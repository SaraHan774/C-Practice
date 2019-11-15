//
// Created by sarah on 11/15/2019.
// Already Printed !
//

#include <iostream>
using namespace std;

class Object{
public:
    static int counter;
    Object(){
        ++counter;
    }
};

int Object::counter = 0;

class Character : public Object{
protected:
    //protected -> needs getter and setter
    char ch;
public:
    Character() {

    }

    Character(char c){
        this -> ch = c;
    }
    Character operator+(Character &character){
         return Character(this -> ch + character.ch);
    }

    char getChar(){
        return ch;
    }

    void setChar(char ch){
        this -> ch = ch;
    }
};

class Digit : public Character{
public:
    Digit(char digit_ch):Character(digit_ch){

    }
    int operator+(Digit &digit){
        return (int(this->ch) + int(digit.ch)) % 10;
    }
};

class Letter : public Character{

};

class Vowel : public Letter{

};

class Consonant : public Letter{

};

int main(){
    //create 2 objs for each class above, and prints the value of obj counter
    Object object = Object();
    Object object1 = Object();

    Character character = Character(char(38));
    Character character1 = Character(char(88));

    Digit digit = Digit(char(32));
    Digit digit1 = Digit(char(34));
    //testing + operator overloading
    cout << digit + digit1 << endl; //result : (32 + 34) % 10 = 6

    Letter letter = Letter();
    Letter letter1 = Letter();

    Vowel vowel = Vowel();
    Vowel vowel1 = Vowel();

    Consonant consonant = Consonant();
    Consonant consonant1 = Consonant();

    cout << object.counter << endl; //result : 12
    return 0;
}