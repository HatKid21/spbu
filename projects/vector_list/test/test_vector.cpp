#include <gtest/gtest.h>

#include "vector.hpp"

using hatkid::Vector;

TEST(VectorTest, InitTest){
    Vector<int> a;
    EXPECT_EQ(a.getSize(), 0);
}

TEST(VectorTest, PushBackTest){
    Vector<int> a;
    a.pushBack(10);
    EXPECT_EQ(a.getSize(),1);
    a.pushBack(11);
    EXPECT_EQ(a.getSize(),2);
}

TEST(VectorTest, HasItemTest){
    Vector<int> a;
    a.pushBack(10);
    EXPECT_TRUE(a.hasItem(10));
    EXPECT_FALSE(a.hasItem(1));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
