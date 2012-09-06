#include <gtest/gtest.h>
#include "foo.cpp"


TEST(AddTest, HH)
{
	EXPECT_EQ(3, Add(1, 2));
//	ASSERT_EQ(6, Add(3, 4));
	ASSERT_EQ(5, Add(3, 4));
	ASSERT_EQ(7, Add(3, 4));
//	EXPECT_EQ(6, Add(3, 4));
//	EXPECT_EQ(5, Add(3, 4));
//	EXPECT_EQ(7, Add(3, 4));
}

TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}
