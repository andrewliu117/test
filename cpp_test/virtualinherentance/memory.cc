// 通过虚继承类的内存分布，一窥虚继承的实现原理

#include <iostream>

using namespace std;

class top{
	public:
		top(long i):_i(i){}
		top(){}
		virtual void a() {cout << "this is top::a()" << endl;}
		virtual void b() {cout << "this is top::b()" << endl;}
		long _i;
};

class middle1: virtual public top{
	public:
		middle1(long j):top(100),_j(j){}
		virtual void b() {cout << "this is middle1::b()" << endl;}
		virtual void c() {cout << "this is middle1::c()" << endl;}
		virtual void m() {cout << "this is middle1::m()" << endl;}
		long _j;
};

class middle2: virtual public top{
	public:
		middle2(long k, long m):_k(k),_m(m){}
		virtual void d() {cout << "this is middle2::d()" << endl;}
		long _k;
		long _m;
};

class bottom: public middle1, public middle2{
	public:
		bottom():top(5936l), middle1(5937l), middle2(5938l, 5939l), _n(10000){}
		virtual void b() {cout << "this is bottom::b()" << endl;}
		long _n;
};

typedef void (*func)(void);

int main(void) {
	long* pobj;
	func pfunc;

	cout << "---memory of middle1---" << endl;
	middle1 m1(101);
	pobj = (long*)&m1;
	pfunc = (func)((long*)*((long*)(pobj[0])));
	cout << "middle1[0]:    vtab(0) | " << hex << (long*)(pobj[0]) << dec << " | "; pfunc();
	cout << "middle1[1]:         _j | " << (long)pobj[1] << endl;
	pfunc = (func)((long*)*((long*)(pobj[2])));
	cout << "    top[0]:    vtab(0) | " << hex << (long*)(pobj[2]) << dec << " | "; pfunc();
	cout << "    top[1]:         _i | " << (long)pobj[3] << endl;

	cout << endl << "---vtable of middle1---" << endl;
	cout << "middle1[0]: offset(-3) | " << hex << ((long*)pobj[0] - 3) << dec << " | " << (long)*((long*)pobj[0] - 3) << endl;
	cout << "            offset(-2) | " << hex << ((long*)pobj[0] - 2) << dec << " | " << (long)*((long*)pobj[0] - 2) << endl;
	cout << "            offset(-1) | " << hex << ((long*)pobj[0] - 1) << " | " << (long)*((long*)pobj[0] - 1) << "; typeinfo for middle1" << endl;
	pfunc = (func)((long*)*((long*)(pobj[0])));
	cout << "               vtab(0) | " << hex << (long*)(pobj[0]) << dec << " | "; pfunc();
	pfunc = (func)((long*)*((long*)(pobj[0]) + 1));
	cout << "               vtab(1) | " << hex << (long*)(pobj[0]) + 1 << dec << " | "; pfunc();
	pfunc = (func)((long*)*((long*)(pobj[0]) + 2));
	cout << "               vtab(2) | " << hex << (long*)(pobj[0]) + 2 << dec << " | "; pfunc();
	cout << "               vtab(3) | " << hex << ((long*)(pobj[0])+3) << dec << " | " << *((long*)(pobj[0])+3) << "; end of vtable" << endl;
	cout << "    top[0]: offset(-3) | " << hex << ((long*)pobj[2] - 3) << dec << " | " << (long)*((long*)pobj[2] - 3) << endl;
	cout << "            offset(-2) | " << hex << ((long*)pobj[2] - 2) << dec << " | " << (long)*((long*)pobj[2] - 2) << endl;
	cout << "            offset(-1) | " << hex << ((long*)pobj[2] - 1) << " | " << (long)*((long*)pobj[2] - 1) << "; typeinfo for middle1" << endl;
	pfunc = (func)((long*)*((long*)(pobj[2])));
	cout << "               vtab(0) | " << hex << (long*)(pobj[2]) << dec << " | "; pfunc();
	cout << "               vtab(1) | " << hex << (long*)(pobj[2]) + 1 << " | " << *((long*)(pobj[2])+1) << "; virtual thunk to middle1::b()" << endl;
	cout << "               vtab(2) | " << hex << (long*)(pobj[2]) + 2 << " | " << *((long*)(pobj[2])+2) << "; end of vtable" << endl;
	cout << "               vtab(3) | " << hex << (long*)(pobj[2]) + 3 << " | " << *((long*)(pobj[2])+3) << "; end of vtable" << endl;
	cout << "               vtab(4) | " << hex << (long*)(pobj[2]) + 4 << " | " << *((long*)(pobj[2])+4) << "; end of vtable" << endl;

	cout << endl << endl << "--- bottom---" << endl;

	bottom bo;
	pobj = (long*) &bo;

	cout << "bo[0]: offset	|	" << dec << (long)*((long*)pobj[0] - 3) << endl;
	cout << "bo[1]:       	|	" << pobj[1] << endl; 
	cout << "bo[2]: offset	|	" << dec << (long)*((long*)pobj[2] - 3) << endl;
	cout << "bo[3]:       	|	" << pobj[3] << endl; 
	cout << "bo[4]:       	|	" << pobj[4] << endl; 
	cout << "bo[5]:       	|	" << pobj[5] << endl; 
	
	pfunc = (func)((long*)*((long*)(pobj[0])));
	pfunc();
}
