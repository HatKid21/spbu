#include "sortings.hpp"

void sort::merge(int* left, int* mid, int* right){
	int* i = left;
	int* j = mid;
	int size = right - left;
	int ar[size];
	int k =0;

	while (i < mid && j < right){
		if (*i < *j){
			ar[k++] = *i++;	
		} else{
			ar[k++] = *j++;
		}
	}

	while (i < mid){
		ar[k++] = *i++;
	}

	while (j < right){
		ar[k++] = *j++;
	}

	for (int i = 0; i < size; i++){
		*(left + i) = ar[i];
	}

}

void sort::mergeSort(int* left, int* right){
	int size = right - left;
	if (size <= 1){
		return;
	}

	int* mid = left + size / 2;

	mergeSort(left,mid);
	mergeSort(mid,right);

	merge(left,mid,right);
}

