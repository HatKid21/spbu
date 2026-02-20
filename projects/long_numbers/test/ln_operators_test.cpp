#include <gtest/gtest.h>

#include "long_number.hpp"

const hatkid::LongNumber ONE{"1"};
const hatkid::LongNumber ZERO{};
const hatkid::LongNumber VAL_101{"101"};
const hatkid::LongNumber VAL_99{"99"};
const hatkid::LongNumber VAL_2{"2"};
const hatkid::LongNumber VAL_4{"4"};


TEST(LongNumberOperations, AddOperation){

    EXPECT_EQ(ONE + ONE, VAL_2);
    EXPECT_EQ(VAL_99 + VAL_2, VAL_101);
    EXPECT_EQ(ONE + ZERO, ONE);

}
