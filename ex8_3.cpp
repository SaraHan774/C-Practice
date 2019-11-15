//
// Created by sarah on 11/15/2019.
//

#include <iostream>
#include <string>
using namespace std; 

class TV{
    int size;
public:
    TV(){ size = 20; }
    TV(int size){ this -> size = size; }
    int getSize(){ return size;}
};

class WideTV : public TV{
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size){
        this -> videoIn = videoIn;
    }
    bool getVideoIn(){ return videoIn; }
};

class SmartTV : public WideTV{
    string ipAddr;
public:
    SmartTV(string ipAddr, int size) : WideTV(size, true){
        this -> ipAddr = ipAddr; 
    }
    
    string getIpAddr(){ return ipAddr; }
};

int main(){
    SmartTV htv("190.01.21.123", 32); 
    cout << "size : " << htv.getSize() << endl; 
    cout << "videoIn : " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP : " << htv.getIpAddr() << endl; 
}