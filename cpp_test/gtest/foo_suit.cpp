#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class foo{
public:
	int add(int a, int b){return a+b;}
};

class footest: public testing::Test {
	protected:
		static void SetUpTestCase() {
			pfoo = new foo();
		}

		static void TearDownTestCase() {
			delete pfoo;
			pfoo = NULL;
		}
	
		static class foo* pfoo;
};

foo* footest::pfoo = NULL;

//T* FooTest::shared_resource_ = NULL;


TEST_F(footest, testadd)
{
	int sum = pfoo->add(1, 2);
	//cout << yellow << "sum is" << sum << endl;
	cout << "sum is" << sum << endl;

	EXPECT_EQ(3, pfoo->add(1, 2));
}

TEST_F(footest, testadd1)
{

	EXPECT_EQ(4, pfoo->add(1, 2));
}
