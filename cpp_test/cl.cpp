/**
=========================================================================
 Author: Charlse.Zhang
 Email: feiyuwgmail.com
 File Name: cl.cpp
 Description: 
   
 Edit History: 
   2012-06-21    File created.
=========================================================================
**/
#include <iostream>

using namespace std;
class a{
public:
	a(){i=10;}
	void print(){
		cout << "in class a, i = " << i << endl;
	}
protected:
	int i;
};

class b:public a{
public:
	void set(int tmp){
		i = tmp;
	}
};

int main(){
	a ca;
	ca.i = 100;
	b cb;
	cb.set(11);
	cb.print();
}
