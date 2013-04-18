/**
=========================================================================
 Author: Charlse.Zhang
 Email: feiyuwgmail.com
 File Name: a.cpp
 Description: 
   
 Edit History: 
   2012-06-11    File created.
=========================================================================
**/

#include <iostream>
using namespace std;
int main(void)
{
	int a, b;
	int *x, *y;
	x = &a;
	y = &b;
	*x = 10;
	*y = *x;
	x = y;
	*x = 20;
	cout<<a<<' '<<b<<endl;

	cout << sizeof(int) << endl;
	
	int map[10][10];
	cout << sizeof(map) << endl;
	cout << sizeof(map[0]) << endl;
	//int *ptr;
	//ptr=(int *)0x8000;
	//*ptr=3;
	//cout << *ptr<< endl;

    int mod = -5;
    cout << "--- mod(-5) % 10" << endl;
    cout << mod % 10 << endl;
}
