#include <iostream>

using namespace std;

static int g_static;

void foo(void){
	static int in_foo;
	cout << "in_foo = " << in_foo << endl;
	cout << "address of in_foo = " << &in_foo << endl;
}

int main(void){
	cout << "g_static = " << g_static << endl;
	cout << "address of g_static = " << &g_static << endl;
	static int in_main;
	cout << "in_main = " << in_main << endl;
	cout << "address of in_main = " << &in_main << endl;

	foo();
}
