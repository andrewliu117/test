#include <iostream>

using namespace std;

class st{
public:
	void add(){m++;}
	void print() { cout << "m is:" << m << endl;}
private:
	static int m;
};

int st::m = 0;

int main(void)
{
	st a;
	st b;
	a.print();
	a.add();
	a.print();
	cout << "-----------" << endl;
	b.print();
	b.add();
	b.print();
}
