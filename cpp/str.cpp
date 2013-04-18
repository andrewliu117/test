/**
=========================================================================
 Author: Charlse.Zhang
 Email: feiyuwgmail.com
 File Name: str.cpp
 Description: 
   
 Edit History: 
   2012-06-06    File created.
=========================================================================
**/
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int main(void)
{
	string str = "";
	cout << str.length() << endl;
	if (str[str.length() - 1] != ','){
		cout << "not equal" << endl;
	}
	cout << "[" << str[str.length() - 1] << "]" <<  endl;
	
	str = "haha1";
	//str = str + string.tostring(12);
	stringstream sstr;
	sstr << str << 12;
	str = sstr.str();
	cout << str << endl;
	cout << str.length() << endl;
	str[str.length() - 1] = 0;
	cout << str << endl;
	cout << str.length() << endl;
    
    str="liuhj@github.com:/home/andrew/temep/";
    cout << str.substr(str.find(":") + 1) << endl;

}
