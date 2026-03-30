#include "doubly_linked_list.hpp"

#include <iostream>

using hatkid::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* cur = begin;
    while (cur != nullptr){
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    begin = nullptr;
    end = nullptr;
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
    while (cur != nullptr){
        if (cur->value == value){
            return true;
        }
        cur = cur->next;
    }
    return false;
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
        end = node;
    } else{
        end->next = node;
        node->prev = end;
        end = node;
    }
}

template<typename T>
bool DoublyLinkedList<T>::removeFirst(const T& value) noexcept {
	Node* cur = begin;

    while (cur != nullptr){
        if (cur->value == value){
            break;
        }
        cur = cur->next;
    }

    if (cur == nullptr){
        return false;
    }

    if (cur->next != nullptr){
        cur->next->prev = cur->prev;
    } else{
        end = cur->prev;
    }

    if (cur->prev != nullptr){
        cur->prev->next = cur->next;
    } else{
        begin = cur->next;
    }
    delete cur;
    return true;
}
