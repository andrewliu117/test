

#include <iostream>

using namespace std;

class base{
public:
	virtual void f(){ cout << "in base::~base()" << endl; }
	int i;
};

class base1 {
public:
	void f(){ cout << "in base1::~base1()" << endl; }
	int i;
};

int main(void) {
	cout << sizeof(base) << endl;
	cout << sizeof(base1) << endl;

}
