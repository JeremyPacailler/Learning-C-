#pragma once

#include <iostream>
#include "PerformanceClock.hpp"

namespace JPContainer {
	template <typename T> class Vector {
	private:
		T* arr;

		int capacity;
		int current;

	public:
		Vector() {
			arr = new T[1];
			capacity = 1;
			current = 0;
		}

		/*Vector(std::initializer_list<T> l) {
			capacity = 2 * l.size();
			current = l.size();

			for (const auto& x : l) {
				push(x);
			}
		}*/

		~Vector() { delete[] arr; }

		void push(T data) {
			if (current == capacity) {
				T* temp = new T[2 * capacity];

				for (int i = 0; i < capacity; i++) {
					temp[i] = arr[i];
				}

				delete[] arr;
				capacity *= 2;
				arr = temp;
			}
			arr[current] = data;
			current++;
		}

		void push(T data, int index) {
			if (index == capacity)
				push(data);
			else
				arr[index] = data;
		}

		T get(int index) {
			if (index < current)
				return arr[index];

			return -1;
		}

		void pop() { current--; }

		const int size() const { return current; }
		const int getCapacity() const { return capacity; }

		void print() {
			PerformanceClock clock;
			for (int i = 0; i < current; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
			
			
	};
}
