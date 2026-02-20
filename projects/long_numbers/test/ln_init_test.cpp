#include <gtest/gtest.h>

#include "long_number.hpp"

const hatkid::LongNumber ZERO{};
const hatkid::LongNumber VAL_123{"123"};
const hatkid::LongNumber VAL_123_NEG{"-123"};

TEST(LongNumberInitialization, DefaultConstructor){
   
    hatkid::LongNumber def;

    EXPECT_FALSE(def.is_negative());

}

TEST(LongNumberInitialization, StringConstructor){
    
    EXPECT_FALSE(VAL_123.is_negative());
    EXPECT_TRUE(VAL_123_NEG.is_negative());

}

TEST(LongNumberInitialization, StringAssigment){
    
    hatkid::LongNumber test_zero = "0";
    hatkid::LongNumber test_123 = "123";
    hatkid::LongNumber test_123_neg = "-123";

    EXPECT_EQ(test_zero, ZERO);
    EXPECT_EQ(test_123, VAL_123);
    EXPECT_EQ(test_123_neg, VAL_123_NEG);

}

TEST(LongNumberInitialization, CopyAssigment){

    hatkid::LongNumber test_zero = ZERO;
    hatkid::LongNumber test_123 = VAL_123;
    hatkid::LongNumber test_123_neg = VAL_123_NEG;

    EXPECT_EQ(test_zero, ZERO);
    EXPECT_EQ(test_123, VAL_123);
    EXPECT_EQ(test_123_neg, VAL_123_NEG);

}

TEST(LongNumberInitialization, MoveAssigment){

    hatkid::LongNumber test_123 = hatkid::LongNumber{"123"};

    EXPECT_EQ(test_123, VAL_123);
    
}



