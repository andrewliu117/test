#include <string> 
#include <iostream> 
#include <map> 

using namespace std;

int main(void)
{
	map<string, int> mymap;
	mymap["haha1"] = 1;
	mymap["haha2"] = 2;
	mymap["haha3"] = 3;
	mymap["haha4"] = 4;

	int &mval = mymap["mval"];
	mval = 13;

	map<string, int>::iterator  iter;
	for (iter = mymap.begin();iter != mymap.end(); iter++){
		cout << iter->first << " = " << iter->second << endl;
	}

	cout << "constmap" << endl;
	const map<string, int> &constmap = mymap;
	map<string, int>::const_iterator  const_iter;
	for (const_iter = mymap.begin();const_iter != mymap.end(); const_iter++){
		cout << const_iter->first << " = " << const_iter->second << endl;
	}
	cout << "mymap.clear()" << endl;
	mymap.clear();
	for (iter = mymap.begin();iter != mymap.end(); iter++){
		cout << iter->first << " = " << iter->second << endl;
	}

	
}
