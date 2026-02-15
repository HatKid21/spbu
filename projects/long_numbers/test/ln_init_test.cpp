#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(LongNumberConstructor, DefaultConstructor){
    hatkid::LongNumber ln1;
    
    EXPECT_FALSE(ln1.is_negative());

}
