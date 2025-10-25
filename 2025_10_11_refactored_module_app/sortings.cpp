#include "sortings.hpp"

void hatkid::sort::merge(int* leftArrayPtr, int* midArrayPtr, int* rightArrayPtr) {
	int* lPtr = leftArrayPtr;
	int* rPtr = midArrayPtr;
	int size = rightArrayPtr - leftArrayPtr;
	int* tempArray = new int[size];
	int k = 0;

	while (lPtr < midArrayPtr && rPtr < rightArrayPtr) {
		if (*lPtr < *rPtr) {
			tempArray[k++] = *lPtr++;	
		} else {
			tempArray[k++] = *rPtr++;
		}
	}

	while (lPtr < midArrayPtr) {
		tempArray[k++] = *lPtr++;
	}

	while (rPtr < rightArrayPtr) {
		tempArray[k++] = *rPtr++;
	}

	for (int i = 0; i < size; i++) {
		*(leftArrayPtr + i) = tempArray[i];
	}
	
	delete[] tempArray;
}

void hatkid::sort::mergeSort(int* leftArrayPtr, int* rightArrayPtr) {
	int size = rightArrayPtr - leftArrayPtr;
	if (size <= 1) {
		return;
	}

	int* midArrayPtr = leftArrayPtr + size / 2;

	mergeSort(leftArrayPtr, midArrayPtr);
	mergeSort(midArrayPtr, rightArrayPtr);

	merge(leftArrayPtr, midArrayPtr, rightArrayPtr);
}

