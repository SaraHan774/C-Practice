// ofstream::open
#include <fstream>
using namespace std;

int main () {

  ofstream outfile;

  outfile.open ("test.txt", ofstream::out | ofstream::app);
  outfile << "This sentence is appended to the file content\n";
  outfile.close();

  return 0;
}