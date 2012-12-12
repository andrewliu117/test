// 通过内存分布，一窥虚继承的实现原理

#include <iostream>

using namespace std;

class top{
public:
	top():_i(5937){}
   void printself(){cout << "this is in top::printself" << endl;}
   long _i;
};

class middle1: virtual public top{
public:
   void printself(){cout << "this is in middle1::printself" << endl;}
};

class middle2: virtual public top{
public:
   void printself(){cout << "this is in middle2::printself" << endl;}
};

class bottom: public middle1, public middle2{
public:
	void printself(){cout << "this is in bottom::printself" << endl;}
};

 typedef void(*func)(void);

int main(void){
	long** pVtab;
	func pfunc;

	bottom bo;
	pVtab = (long**) &bo;
	cout << bo._i << endl;
	cout << (long)*pVtab[0] << endl;
	cout << (long)*pVtab[1] << endl;
	cout << (long)*pVtab[3] << endl;


	//cout << "[0] D::B1::_vptr->" << endl;
	//cout << (long)*pVtab[0] << endl;
	//cout << (long)*pVtab[1] << endl;
	//cout << (long)*((char*)pVtab[0] + ((long)*pVtab[0])) << endl;
	//pfunc = (func)pVtab[1];
	//cout << "     [0] ";    pfunc();
}
