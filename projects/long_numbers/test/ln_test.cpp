#include <gtest/gtest.h>

#include "long_number.hpp"

const hatkid::LongNumber ONE{"1"};
const hatkid::LongNumber ZERO{};
const hatkid::LongNumber VAL_101{"101"};
const hatkid::LongNumber VAL_99{"99"};
const hatkid::LongNumber VAL_2{"2"};
const hatkid::LongNumber VAL_4{"4"};
const hatkid::LongNumber ONE_NEG{"-1"};
const hatkid::LongNumber VAL_123{"123"};
const hatkid::LongNumber VAL_123_COPY{"123"};
const hatkid::LongNumber VAL_123_NEG{"-123"};
const hatkid::LongNumber VAL_124{"124"};

// Constructors

TEST(LongNumberTest, DefaultConstructor){
   
    hatkid::LongNumber def;

    EXPECT_FALSE(def.isNegative());

}

TEST(LongNumberTest, StringConstructor){
    
    EXPECT_FALSE(VAL_123.isNegative());
    EXPECT_TRUE(VAL_123_NEG.isNegative());

}

// Assignments

TEST(LongNumberTest, StringAssigment){
    
    hatkid::LongNumber testZero = "0";
    hatkid::LongNumber test123 = "123";
    hatkid::LongNumber test123Neg = "-123";

    EXPECT_EQ(testZero, ZERO);
    EXPECT_EQ(test123, VAL_123);
    EXPECT_EQ(test123Neg, VAL_123_NEG);

}

TEST(LongNumberTest, CopyAssigment){

    hatkid::LongNumber testZero = ZERO;
    hatkid::LongNumber test123 = VAL_123;
    hatkid::LongNumber test123Neg = VAL_123_NEG;

    EXPECT_EQ(testZero, ZERO);
    EXPECT_EQ(test123, VAL_123);
    EXPECT_EQ(test123Neg, VAL_123_NEG);

}

TEST(LongNumberTest, MoveAssigment){

    hatkid::LongNumber test123 = hatkid::LongNumber{"123"};

    EXPECT_EQ(test123, VAL_123);
    
}

// Comparation

TEST(LongNumberTest, ComparationEqual){
    
    EXPECT_TRUE(VAL_123 == VAL_123_COPY);
    EXPECT_FALSE(ONE == ZERO);
    EXPECT_FALSE(VAL_123 == VAL_123_NEG);
    EXPECT_TRUE(ZERO == ZERO);

}

TEST(LongNumberTest, ComparationNotEqual){
    
    EXPECT_FALSE(VAL_123 != VAL_123_COPY);
    EXPECT_TRUE(ONE != ZERO);
    EXPECT_TRUE(VAL_123 != VAL_123_NEG);
    EXPECT_FALSE(ZERO != ZERO);

}

TEST(LongNumberTest, ComparationGreater){

    EXPECT_TRUE(VAL_124 > VAL_123);
    EXPECT_TRUE(VAL_123 > VAL_123_NEG);
    EXPECT_TRUE(ONE > ZERO);
    EXPECT_FALSE(VAL_123 > VAL_123_COPY);
    EXPECT_FALSE(VAL_123_NEG > VAL_123);

}

TEST(LongNumberTest, ComparationLess){

    EXPECT_TRUE(VAL_123_NEG < VAL_123);
    EXPECT_FALSE(VAL_124 <  VAL_123);
    EXPECT_FALSE(ZERO < ZERO);
    EXPECT_FALSE(ONE < ZERO);
    EXPECT_FALSE(ONE < ONE_NEG);

}

// Operations

TEST(LongNumberTest, AddOperation){

    EXPECT_EQ(ONE + ONE, VAL_2);
    EXPECT_EQ(VAL_99 + VAL_2, VAL_101);
    EXPECT_EQ(ONE + ZERO, ONE);

}
