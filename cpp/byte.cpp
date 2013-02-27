#include <iostream>
#include <fstream>

using namespace std;

#define SET_INDEX_BIT(a) ((a)|0x01)
#define IS_INDEX_BIT_SET(a) ((a) & 0x01)
#define UNSET_INDEX_BIT(a) ((a)&(~0x01))

int main()
{
	unsigned b = 0;
	b = SET_INDEX_BIT(b);
	
	cout << b << endl;
	b = b | 0x02;
	cout << b << endl;
	b = UNSET_INDEX_BIT(b);
	if (IS_INDEX_BIT_SET(b)){
		cout << "yes, it's set"<< endl;
	}
	else{
		cout << " not set " << endl;
	}
	cout << b << endl;



     ifstream ifs("");
     string line;
     while(getline(ifs, line)) 
     {
	cout <<  line << endl;
     }
     ifs.close();
	cout << "after load" << endl;
}
