#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(LongNumberComparation, ComparationEqual){
    hatkid::LongNumber ln1("123");
    hatkid::LongNumber ln2("123");
    hatkid::LongNumber ln3("124");

    EXPECT_TRUE(ln1 == ln2);
    EXPECT_FALSE(ln1 == ln3);
}

TEST(LongNumberComparation, ComparationNotEqual){
    hatkid::LongNumber ln1("123");
    hatkid::LongNumber ln2("123");
    hatkid::LongNumber ln3("124");
    
    EXPECT_FALSE(ln1 != ln2);
    EXPECT_TRUE(ln1 != ln3);

}

TEST(LongNumberComparation, ComparationGreater){
    hatkid::LongNumber ln1("123123123");
    hatkid::LongNumber ln2("123123124");

    EXPECT_FALSE(ln1 > ln2) << "123123123 больше 123123124";
    EXPECT_TRUE(ln2 > ln1) << "123123124 меньше 123123123";
}

TEST(LongNumberComparation, ComparationLess){
    hatkid::LongNumber ln1("123123123");
    hatkid::LongNumber ln2("123123124");
    
    EXPECT_TRUE(ln1 < ln2);
    EXPECT_FALSE(ln2 < ln1);

}
