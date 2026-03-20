#include <gtest/gtest.h>

#include "vector.hpp"

using hatkid::Vector;

TEST(VectorTest, InitTest){
    Vector<int> a;
    EXPECT_EQ(a.getSize(), 0);
}

TEST(VectorTest, IntPushBackTest){
    Vector<int> a;
    a.pushBack(10);
    EXPECT_EQ(a.getSize(),1);
    a.pushBack(11);
    EXPECT_EQ(a.getSize(),2);
    a.pushBack(12);
    EXPECT_EQ(a.getSize(),3);
    a.pushBack(1);
    EXPECT_EQ(a.getSize(),4);
    a.print();
}

TEST(VectorTest, CharPushBackTest){
    Vector<char> a;
    a.pushBack('1');
    EXPECT_EQ(a.getSize(),1);
    a.pushBack('a');
    EXPECT_EQ(a.getSize(),2);
    a.pushBack('b');
    EXPECT_EQ(a.getSize(),3);
    a.pushBack('c');
    EXPECT_EQ(a.getSize(),4);
    a.print();
}

TEST(VectorTest, IntHasItemTest){
    Vector<int> a;
    a.pushBack(10);
    EXPECT_TRUE(a.hasItem(10));
    EXPECT_FALSE(a.hasItem(1));
}

TEST(VectorTest, CharHasItemTest){
    Vector<char> c;
    c.pushBack('a');
    EXPECT_TRUE(c.hasItem('a'));
    EXPECT_FALSE(c.hasItem('b'));
}

TEST(VectorTest, IntRemoveFirstTest){
    Vector<int> a;
    for (int i = 0; i < 20; i++){
        a.pushBack(i);
    }
    EXPECT_EQ(a.getSize(),20);
    a.removeFirst(5);
    EXPECT_EQ(a.getSize(),19);
    EXPECT_FALSE(a.hasItem(5));
    a.pushBack(2);
    a.removeFirst(2);
    EXPECT_EQ(a.getSize(),19);
    a.print();
}

TEST(VectorTest, CharRemoveFirstTest){
    Vector<char> c;
    for (int i = 0; i < 20; i++){
        c.pushBack('a'+ i);
    }
    EXPECT_EQ(c.getSize(),20);
    c.removeFirst('a');
    EXPECT_EQ(c.getSize(),19);
    c.pushBack('b');
    c.removeFirst('b');
    EXPECT_EQ(c.getSize(),19);
    c.print();
}

TEST(VectorTest, IntInsertTest){
    Vector<int> a;
    for (int i = 0; i < 10; i++){
        a.pushBack(i);
    }
    a.insert(5,100);
    EXPECT_EQ(a.getSize(),11);
    a.insert(2,10000);
    EXPECT_EQ(a.getSize(),12);
    EXPECT_TRUE(a.hasItem(100));
    EXPECT_TRUE(a.hasItem(10000));
    a.print();
}

TEST(VectorTest, CharInsertTest){
    Vector<char> c;
    for (int i = 0; i < 10; i++){
        c.pushBack('a' + i);
    }
    c.insert(5,'5');
    EXPECT_EQ(c.getSize(),11);
    c.insert(2,'4');
    EXPECT_EQ(c.getSize(),12);
    EXPECT_TRUE(c.hasItem('4'));
    EXPECT_TRUE(c.hasItem('5'));
    c.print();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
