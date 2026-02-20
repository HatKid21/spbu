#include <gtest/gtest.h>

#include "long_number.hpp"

const hatkid::LongNumber ZERO{};
const hatkid::LongNumber ONE{"1"};
const hatkid::LongNumber ONE_NEG{"-1"};
const hatkid::LongNumber SAME1{"123"};
const hatkid::LongNumber SAME2{"123"};
const hatkid::LongNumber SAME_NEG{"-123"};
const hatkid::LongNumber TEST{"124"};

TEST(LongNumberComparation, ComparationEqual){
    
    EXPECT_TRUE(SAME1 == SAME2);
    EXPECT_FALSE(ONE == ZERO);
    EXPECT_FALSE(SAME1 == SAME_NEG);
    EXPECT_TRUE(ZERO == ZERO);

}

TEST(LongNumberComparation, ComparationNotEqual){
    
    EXPECT_FALSE(SAME1 != SAME2);
    EXPECT_TRUE(ONE != ZERO);
    EXPECT_TRUE(SAME1 != SAME_NEG);
    EXPECT_FALSE(ZERO != ZERO);

}

TEST(LongNumberComparation, ComparationGreater){

    EXPECT_TRUE(TEST > SAME1);
    EXPECT_TRUE(SAME1 > SAME_NEG);
    EXPECT_TRUE(ONE > ZERO);
    EXPECT_FALSE(SAME1 > SAME2);
    EXPECT_FALSE(SAME_NEG > SAME1);

}


TEST(LongNumberComparation, ComparationLess){

    EXPECT_TRUE(SAME_NEG < SAME1);
    EXPECT_FALSE(TEST <  SAME1);
    EXPECT_FALSE(ZERO < ZERO);
    EXPECT_FALSE(ONE < ZERO);
    EXPECT_FALSE(ONE < ONE_NEG);

}
