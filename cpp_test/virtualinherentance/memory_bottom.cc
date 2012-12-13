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
		virtual void c() {cout << "this is middle1::c()" << endl;}
		virtual void b() {cout << "this is middle1::b()" << endl;}
		long _j;
};

class middle2: virtual public top{
	public:
		middle2(long k, long m):_k(k),_m(m){}
		virtual void d() {cout << "this is middle2::d()" << endl;}
		long _k;
		long _m;
};

class bottom: virtual public middle1, virtual public middle2{
	public:
		bottom():top(5936l), middle1(5937l), middle2(5938l, 5939l), _n(10000){}
		virtual void b() {cout << "this is bottom::b()" << endl;}
		virtual void e() {cout << "this is bottom::e()" << endl;}
		long _n;
};

typedef void (*func)(void);

int main(void) {
	long* pobj;
	func pfunc;

	cout << "--- member of bottom---" << endl;
	bottom bo;
	pobj = (long*) &bo;

	cout << "bo._n: " << bo._n << endl;
	cout << "   _j: " << bo._j << endl;
	cout << "   _i: " << bo._i << endl;
	cout << "   _k: " << bo._k << endl;
	cout << "   _m: " << bo._m << endl;

	cout << endl << endl << "--- memory of bottom---" << endl;

	pfunc = (func)((long*)*((long*)(pobj[0])));
	cout << "     bo[0]:    vtab(0) | " << hex << (long*)(pobj[0]) << dec << " | "; pfunc();
	cout << "     bo[1]:         _n | " << pobj[1] << endl; 
	pfunc = (func)((long*)*((long*)(pobj[2])));
	cout << "middle1[0]:    vtab(0) | " << hex << (long*)(pobj[2]) << dec << " | "; pfunc();
	cout << "middle1[1]:         _j | " << pobj[3] << endl; 
	pfunc = (func)((long*)*((long*)(pobj[4])));
	cout << " bottom[0]:    vtab(0) | " << hex << (long*)(pobj[4]) << dec << " | "; pfunc();
	cout << " bottom[1]:         _i | " << pobj[5] << endl; 
	pfunc = (func)((long*)*((long*)(pobj[6])));
	cout << "middle2[0]:    vtab(0) | " << hex << (long*)(pobj[6]) << dec << " | "; pfunc();
	cout << "middle2[2]:         _k | " << pobj[7] << endl; 
	cout << "middle2[2]:         _m | " << pobj[8] << endl; 

	cout << endl << endl << "--- vtable of bottom---" << endl;

	// class top
	cout << " bottom[0]: offset(-3) | " << hex << (long*)pobj[0] - 3 << dec << " | " << (long)*((long*)pobj[0] - 3) << endl;
	cout << "            offset(-2) | " << hex << (long*)pobj[0] - 2 << dec << " | " << (long)*((long*)pobj[0] - 2) << endl;
	cout << "            offset(-1) | " << hex << (long*)pobj[0] - 1 << " | " << (long*)*((long*)pobj[0] - 1) << "; typeinfo for bottom" << endl;
	pfunc = (func)((long*)*((long*)(pobj[0])));
	cout << "               vtab(0) | " << hex << (long*)pobj[0] << dec << " | "; pfunc();
	pfunc = (func)((long*)*((long*)(pobj[0]) + 1));
	cout << "               vtab(1) | " << hex << (long*)pobj[0] + 1 << dec << " | "; pfunc();
	cout << "               vtab(2) | " << hex << (long*)pobj[0] + 2 << dec << " | " << *((long*)(pobj[0])+2) << "; end of vtable" << endl;

	// class middle1
	cout << "middle1[0]: offset(-3) | " << hex << (long*)pobj[2] - 3 << dec << " | " << (long)*((long*)pobj[2] - 3) << endl;
	cout << "            offset(-2) | " << hex << (long*)pobj[2] - 2 << dec << " | " << (long)*((long*)pobj[2] - 2) << endl;
	cout << "            offset(-1) | " << hex << (long*)pobj[2] - 1 << " | " << (long*)*((long*)pobj[2] - 1) << "; typeinfo for bottom" << endl;
	pfunc = (func)((long*)*((long*)(pobj[2])));
	cout << "               vtab(0) | " << hex << (long*)pobj[2] << dec << " | "; pfunc();
	cout << "               vtab(1) | " << hex << (long*)pobj[2] + 1 << " | " << (long*)*((long*)pobj[2] + 1) << "; virtual thunk to bottom::b()" << endl;
	cout << "               vtab(2) | " << hex << (long*)pobj[2] + 2 << dec << " | " << *((long*)pobj[2] + 2) << "; end of vtable" << endl;

	// class top 
	cout << "    top[0]: offset(-3) | " << hex << (long*)pobj[4] - 3 << dec << " | " << (long)*((long*)pobj[4] - 3) << endl;
	cout << "            offset(-2) | " << hex << (long*)pobj[4] - 2 << dec << " | " << (long)*((long*)pobj[4] - 2) << endl;
	cout << "            offset(-1) | " << hex << (long*)pobj[4] - 1 << " | " << (long*)*((long*)pobj[4] - 1) << "; typeinfo for bottom" << endl;
	pfunc = (func)((long*)*((long*)(pobj[4])));
	cout << "               vtab(0) | " << hex << (long*)pobj[4] << dec << " | "; pfunc();
	cout << "               vtab(1) | " << hex << (long*)pobj[4] + 1 << " | " << (long*)*((long*)pobj[4] + 1) << "; virtual thunk to bottom::b()" << endl;
	cout << "               vtab(2) | " << hex << (long*)pobj[4] + 2 << dec << " | " << *((long*)pobj[4] + 2) << "; end of vtable" << endl;

	// class middle2
	cout << "middle2[0]: offset(-3) | " << hex << (long*)pobj[6] - 3 << dec << " | " << (long)*((long*)pobj[6] - 3) << endl;
	cout << "            offset(-2) | " << hex << (long*)pobj[6] - 2 << dec << " | " << (long)*((long*)pobj[6] - 2) << endl;
	cout << "            offset(-1) | " << hex << (long*)pobj[6] - 1 << " | " << (long*)*((long*)pobj[6] - 1) << "; typeinfo for bottom" << endl;
	pfunc = (func)((long*)*((long*)(pobj[6])));
	cout << "               vtab(0) | " << hex << (long*)pobj[6] << dec << " | "; pfunc();
	cout << "               vtab(1) | " << hex << (long*)pobj[6] + 1 << dec << " | " << *((long*)pobj[6] + 1) << "; end of vtable" << endl;
}
