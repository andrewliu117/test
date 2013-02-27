
#include <iostream>
using namespace std;
int main(void)
{
	int b = 33;
	cout << b << endl;
	int *ptr;
	ptr=(int *)&b;
	*ptr=3;
	cout << *ptr << endl;
	cout << b << endl;
	cout << &b << endl;
}
