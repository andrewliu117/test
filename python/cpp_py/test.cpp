#include <iostream>
using namespace std;
char const* hello()
{
  return "hello, world";
}
char const* bye(char* str1, int i, char* str2)
{
  using namespace std;
  cout << "str1=" << str1 << ", i=" << i << ", str2=" << str2  <<endl;
  return "hello, world";
}

class a{
public:
	void set(int nu){i = nu;}
	void aprint(){cout << "i=" << i<< endl;}
private:
	int i;
};
