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

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
