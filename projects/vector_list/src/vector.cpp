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
    return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
	// TODO
}

template<typename T>
void Vector<T>::pushBack(const T& value) {
	if (size + 1 > capacity){
        expand();
    }
    
    arr[size] = value;
    size++;

}

template<typename T>
bool Vector<T>::removeFirst(const T& value) {
	// TODO
    return false;
}

template<typename T>
void Vector<T>::expand(){
    capacity *= 2;
    T* temp = new T[capacity];
    for (int i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
