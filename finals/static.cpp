// Example that shows how to use static data member
//
// in this case we use a counter that is shared by all objects
// of type foo to keep track of how many foo objects are around.
//
// we also use a static int to assign unique ids to each object
// 

#include <iostream>
using namespace std;


// definition of the class foo

class foo {
private:
  static int cnt;	// number in memory 
  static int nextid;	// the next id number 

public:
  int id;		// not shared - each object has it's own


  // constructor should update the counter,
  // assign an id and update nextid.

  foo() {
    cnt++;		// update the counter of alive foos
    id = nextid++;	// assign an id
    cout << "foo # " << id << " is alive " << endl;
  }


  // destructor should update (decrement) the counter
  ~foo() {
    cnt--;
    cout << "foo # " << id << " is dead " << endl;
  }

  // print out stats including my id 
  void stats() {
    cout << "I am foo number " << id << endl;
    gstats();
  }

  // print out some stats - available any time
  // even if there are not any foos around!
  static void gstats() {
    cout << "Objects currently alive: " << cnt << endl;
    cout << "Total number ever created: " << nextid << endl;
  }


  // Here is the interesting part!
  // comment out this copy constructor and see what happens!
  // note we don't copy the id - we assign a new one.
  // this helps really keep track of things.

   foo( foo &f) {
    cnt++;		// update the counter of alive foos
    id = nextid++;	// assign an id
    cout << "foo # " << id << " is alive and copied from " << f.id << endl;
  }    
};

// -------------------------------------------------------------------
// we must declare and initialze this outside of the class definition!

int foo::cnt = 0;
int foo::nextid = 0;

// -------------------------------------------------------------------

// Here are some dummy functions that show the effect
// of passing a parameter

void dmy1( foo a ) {
  cout << "called dmy1 ( by value) id is " << a.id <<  endl;
}


void dmy2( foo &a) {
  cout << "called dmy2 (by reference) id is " << a.id << endl;
}

void main(void) {

  // first call the stats method
  foo::gstats();

  // now create some

  foo f1,f2;

  f1.stats();

  // now some foos that will lose scope
  {
    foo a,b,c;
    c.stats();
  }

  // now 3 should be gone (a b and c)
 foo::gstats();

 // now get serious and create a temporary (a copy of f1 is given 
 // to dmy1 but not to dmy2). The interesting part is to compare what
 // happens when this temporary is made with and withou our copy constructor
 // (comment it out and see what happens).

 dmy1(f2);

 dmy2(f2);

 foo::gstats();
}