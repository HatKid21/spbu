#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using hatkid::DoublyLinkedList;

TEST(LinkedListTest, InitTest){
    DoublyLinkedList<int> l;
    EXPECT_EQ(l.getSize(),0);
    l.print();
}

TEST(LinkedListTest, IntPushBackTest){
    DoublyLinkedList<int> l;
    l.pushBack(1);
    EXPECT_EQ(l.getSize(),1);
    l.pushBack(2);
    EXPECT_EQ(l.getSize(),2);
    l.print();
}

TEST(LinkedListTest, CharPushBackTest){
    DoublyLinkedList<char> l;
    l.pushBack('a');
    EXPECT_EQ(l.getSize(),1);
    l.pushBack('b');
    EXPECT_EQ(l.getSize(),2);
    l.print();
}

TEST(LinkedListTest, IntHasItemTest){
    DoublyLinkedList<int> l;
    for (int i = 0; i < 10;i++){
        l.pushBack(i);
    }
    EXPECT_TRUE(l.hasItem(5));
    EXPECT_TRUE(l.hasItem(0));
    EXPECT_FALSE(l.hasItem(11));
    EXPECT_FALSE(l.hasItem(2412));
}

TEST(LinkedListTest, CharHasItemTest){
    DoublyLinkedList<char> l;
    for (int i = 0; i < 10;i++){
        l.pushBack('a' + i);
    }
    EXPECT_TRUE(l.hasItem('a'));
    EXPECT_TRUE(l.hasItem('b'));
    EXPECT_FALSE(l.hasItem('z'));
    EXPECT_FALSE(l.hasItem('x'));
}

TEST(LinkedListTest, IntRemoveFirstTest){
    DoublyLinkedList<int> l;
    for (int i = 0; i < 10; i++){
        l.pushBack(i);
    }
    EXPECT_EQ(l.getSize(),10);
    l.removeFirst(5);
    EXPECT_EQ(l.getSize(),9);
    l.pushBack(2);
    l.removeFirst(2);
    EXPECT_EQ(l.getSize(),9);
    l.print();
}


TEST(LinkedListTest, CharRemoveFirstTest){
    DoublyLinkedList<char> l;
    for (int i = 0; i < 10; i++){
        l.pushBack('a' + i);
    }
    EXPECT_EQ(l.getSize(),10);
    l.removeFirst('a');
    EXPECT_EQ(l.getSize(),9);
    l.pushBack('b');
    l.removeFirst('b');
    EXPECT_EQ(l.getSize(),9);
    l.print();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
