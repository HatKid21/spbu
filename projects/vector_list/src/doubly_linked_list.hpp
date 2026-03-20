#pragma once

#include <cstddef>

namespace hatkid {
	template <typename T> 
	class DoublyLinkedList {
		private:
			class Node {
				public:
					T value;
					Node* prev = nullptr;
					Node* next = nullptr;
					
					Node(const T& value) : value(value) {}
						
					Node(const Node&) = delete;
					Node& operator = (const Node&) = delete;
			};

			Node* begin = nullptr;
			Node* end = nullptr;
public:
			DoublyLinkedList() noexcept {};
			DoublyLinkedList(const DoublyLinkedList&) = delete;
			DoublyLinkedList& operator = (const DoublyLinkedList&) = delete;
			~DoublyLinkedList();
			
			std::size_t getSize() const noexcept;
			bool hasItem(const T& value) const noexcept;
			void print() const noexcept;
			void pushBack(const T& value);
			bool removeFirst(const T& value) noexcept;
	};
}
