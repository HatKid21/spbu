#include <gtest/gtest.h>

#include "sortings.hpp"

TEST(ArrayEquals, AssertEqual) {
	int actual[] = {1,5,2,3,8,10,11,6};

	const int arraySize = sizeof(actual) / sizeof(actual[0]);

	int expected[] = {1,2,3,5,6,8,10,11};

	hatkid::sort::mergeSort(actual, actual + arraySize);

	for (int i = 0; i < arraySize;i++){
		ASSERT_EQ(actual[i],expected[i]) 
			<< "Массив отличается от ожидаемого в индексе "
			<< i;
	}
}


int main(int argc,char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
