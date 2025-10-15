#include <cmath>
#include <iostream>

void countAverage(int* array, int size);
void generateSequence(int* array, int size);
void showArray(int* array, int size);

int main(){
	const int size = 10;
	int array[size];
	
	for (int i = 0; i < 3; i++){
		generateSequence(array,size);
		std::cout << "Последовательность №" << i+1 << ":\n";
		showArray(array,size);
		std::cout << "Среднее арифметическое №" << i+1 << ": ";
		countAverage(array,size);
	}
}

void countAverage(int* array, int size){
	float average = 0;
	for (int i = 0; i < size; i++){
		average += array[i];
	}
	std::cout << average / size << "\n";
}

void generateSequence(int* array, int size){
	for (int i = 0; i < size; i++){
		*(array+i) = rand() % 10;
	}
}

void showArray(int* array, int size){
	for (int i = 0; i < size; i++){
		std::cout << array[i] << " "; 
	}
	std::cout << "\n";
}
