#include "vector.hpp"

#include <iostream>

using hatkid::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 2;

template<typename T>
Vector<T>::Vector() : size(0), capacity(START_CAPACITY) {
    arr = new T[START_CAPACITY];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr;
    size = 0;
    capacity = 0;
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
	if (position > size){
        return false;
    }

    if (size+1 > capacity){
        reallocateForInsert(capacity * 2, position,value);
        return true;
    }

    for (size_t i = size-1; i > position; i--){
        arr[i]= arr[i-1];
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
        reallocateAndCopy(capacity * 2);
    }
    
    arr[size] = value;
    size++;

}

template<typename T>
bool Vector<T>::removeFirst(const T& value) {
    size_t firstInd = size;
    for (size_t i = 0; i < size; i++){
        if (arr[i] == value){
            firstInd = i;
            break;
        }
    }

    if (firstInd == size){
        return false;
    }

    for (size_t i = firstInd; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
    if (size < capacity / 2){
        reallocateAndCopy(capacity / 2);
    }

    return true;
}

template<typename T>
T Vector<T>::get(size_t index){
	return arr[index];
}

//PRIVATE

template<typename T>
void Vector<T>::reallocateAndCopy(size_t newCapacity){
    T* newArr = new T[newCapacity];
    for (size_t i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;

}

template<typename T>
void Vector<T>::reallocateForInsert(size_t newCapacity, size_t position, const T& value){
    T* newArr = new T[newCapacity];
    for (size_t i = 0; i < position; i++){
        newArr[i] = arr[i];
    }

    newArr[position] = value;

    for (size_t i = position; i < size; i++){
        newArr[i+1] = arr[i]; 
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
    size++;


}
