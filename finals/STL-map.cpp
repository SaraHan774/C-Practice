#include <iostream>
#include <map>
#include <string>

using namespace std;

void main() {
	map<string,int> assoc_map;

	assoc_map["Lee"] = 100;
	assoc_map["kim"] = 105;
	
	// iterator based output of all map elements
	for (map<string, int>::iterator  ai = assoc_map.begin(); 
		                             ai != assoc_map.end(); 
									 ai++) {
		cout << ai->first << ":" << ai->second << endl;;
	}
	assoc_map["Gang"] = 120; // add further entry

	int v = assoc_map.find("kim") -> second; // find entry "kim"
	cout << v << endl;
	
	assoc_map.erase("Lee"); // delete entry "Lee" from the map
	
	// Lee is not inside assoc_map any longer!
	map<string, int>::iterator itr = assoc_map.find("Lee");
	// If the find fails itr is equal to assoc_map.end()
	if (itr == assoc_map.end()) {
		cout << "There seems to be no entry \"Lee\"" << endl;
	}
}