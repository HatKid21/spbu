#include "doubly_linked_list.hpp"

#include <iostream>

using hatkid::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* cur = begin;
    while (cur != nullptr){
        if (cur->prev != nullptr){
            delete cur->prev;
        }
        cur = cur->next;
    }
    delete cur;
}

template<typename T>
std::size_t DoublyLinkedList<T>::getSize() const noexcept {
	Node* cur = begin;
    if (begin == nullptr){
        return 0;
    }
    size_t count = 1;
    while (cur->next != nullptr){
        count++;
        cur = cur->next;
    }
    return count;
}

template<typename T>
bool DoublyLinkedList<T>::hasItem(const T& value) const noexcept {
	Node* cur = begin;
    if (cur == nullptr){
        return false;
    }
    while (cur->value != value){
        cur = cur->next;
    }
    return cur->value == value;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	Node* cur = begin;
    if (cur == nullptr){
        std::cout << "()";
    }
    while (cur != nullptr){
        std::cout << "(" << cur->value << ")";
        cur = cur->next;
        if (cur != nullptr){
            std::cout << " <-> ";
        }
    }
    std::cout << "\n";
}

template<typename T>
void DoublyLinkedList<T>::pushBack(const T& value) {
    Node* node = new Node(value);
    if (begin == nullptr){
        begin = node;
        end = begin;
    } else{
        delete end->next;
        end->next = node;
        node->prev = end;
        end = node;
    }
}

template<typename T>
bool DoublyLinkedList<T>::removeFirst(const T& value) noexcept {
	Node* cur = begin;
    if (cur == nullptr){
        return false;
    }
    while (cur->value != value){
        cur = cur->next;
    }
    if (cur->value == value){
        Node* prev = cur->prev;
        Node* next = cur->next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        return true;
    }
    return false;
}
