#pragma once

#include <cstddef>

namespace hatkid {
	template <typename T> 
	class Vector {
		private:
			static const std::size_t START_CAPACITY;

			T* arr = nullptr;
			std::size_t capacity = START_CAPACITY;
			std::size_t size = 0;

		public:
			Vector();
			Vector(const Vector&) = delete;
			Vector& operator = (const Vector&) = delete;
			~Vector();
			
			std::size_t getSize() const noexcept;
			bool hasItem(const T& value) const noexcept;
			bool insert(const std::size_t position, const T& value);
			void print() const noexcept;
			void pushBack(const T& value);
			bool removeFirst(const T& value);
			T get(size_t index);

        private:
            void reallocateAndCopy(size_t newCapacity);
            void reallocateForInsert(size_t newCapacity, size_t position, const T& value);
    };
}
