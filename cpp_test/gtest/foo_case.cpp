#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class foo{
public:
	void init() {cout << "foo init" << endl;}
	void finalize() {cout << "foo finalize" << endl;}
	int add(int a, int b) {return a+b;}
};

class footest : public testing::Test{
protected:
	virtual void SetUp(){
		m_foo.init();
	}

	virtual void TearDown(){
		m_foo.finalize();
	}

	foo m_foo;
};

TEST_F(footest, test1)
{
	EXPECT_EQ(4, m_foo.add(1,2));
}

TEST_F(footest, test2)
{
	EXPECT_EQ(3, m_foo.add(1,2));
}
