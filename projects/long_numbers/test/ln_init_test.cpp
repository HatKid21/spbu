#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(LongNumberConstructor, DefaultConstructor){
    hatkid::LongNumber ln1;
    
    EXPECT_FALSE(ln1.is_negative());
}

TEST(LongNumberConstructor, StringConstructor){
    hatkid::LongNumber ln1("123");
    hatkid::LongNumber ln2("-123");

    EXPECT_FALSE(ln1.is_negative()) ;
    EXPECT_TRUE(ln2.is_negative());
}
