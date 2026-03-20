#include "vector.hpp"

#include <iostream>

using hatkid::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 2;

template<typename T>
Vector<T>::Vector() {
    arr = new T[START_CAPACITY];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template<typename T>
std::size_t Vector<T>::getSize() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::hasItem(const T& value) const noexcept {
	for (std::size_t i = 0; i < size; i++){
        T val = arr[i];
        if (val == value){
            return true;
        }
    }
    return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position >= size or position < 0){
        return false;
    }

    if (size+1 > capacity){
        capacity *= 2;
        mv(0);
    }
    for (size_t i = size-1; i >= position; i--){
        arr[i+1]= arr[i];
    }
    arr[position] = value;
    
    size++;

    return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
    std::cout << "[";
	for (size_t i = 0; i < size; i++){
        std::cout << arr[i];
        if (i+1 != size){
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

template<typename T>
void Vector<T>::pushBack(const T& value) {
	if (size + 1 > capacity){
        capacity *= 2;
        mv(0);
    }
    
    arr[size] = value;
    size++;

}

template<typename T>
bool Vector<T>::removeFirst(const T& value) {
    size_t firstInd = -1;
    for (size_t i = 0; i < size; i++){
        if (arr[i] == value){
            firstInd = i;
            break;
        }
    }

    if (firstInd == -1){
        return false;
    }

    for (size_t i = firstInd; i < size; i++){
        arr[i] = arr[i+1];
    }
    size--;
    if (size < capacity / 2){
        capacity /= 2;
        mv(0);
    }

    return true;
}

//PRIVATE

template<typename T>
void Vector<T>::mv(size_t startIndex){
    T* temp = new T[capacity];
    for (size_t i = startIndex; i < size; i++){
        temp[i-startIndex] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
