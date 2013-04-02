/**
=========================================================================
 Author: Charlse.Zhang
 Email: feiyuwgmail.com
 File Name: string.cpp
 Description: 
   
 Edit History: 
   2012-06-04    File created.
=========================================================================
**/
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string a = "haha,1234,kkk,";
	string b = a.substr(0, a.length() - 1);
	cout << b << endl;
	for(unsigned i = 0; i < b.length(); i++){
		if (b[i] == ','){
			b[i] = ':';
		}
	}
	cout << b << endl;
	for(string::iterator it = b.begin(); it != b.end(); it++){
		if( *it == ':'){
			*it = '.';
		}
	}
	cout << b << endl;
	cout << b.length() << endl;
	cout << b[b.length() -1 ] << endl;

    string a1= "123";
    string a2= "ABC";
    string a3= "abc";
    
    string arr[3] = {a1, a2, a3};
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << endl;
    }
}
