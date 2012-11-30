// 研究构造函数的是否可以使用virtual

#include <iostream>

using namespace std;

class base{
public:
   virtual base(){cout<<"This is base;"<<endl;}
};

class derived: public base{
public:
   virtual derived(){cout<<"This is derived;"<<endl;}
};

int main(void){
	base ba;
	derived de;
}
