#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(LongNumberOperations, AddOperation){
    hatkid::LongNumber ln1("99");
    hatkid::LongNumber ln2("2");
    hatkid::LongNumber ln3("101");
    hatkid::LongNumber ln4("4");

    EXPECT_EQ(ln1+ln2, ln3);
    EXPECT_EQ(ln2+ln2,ln4);

}
