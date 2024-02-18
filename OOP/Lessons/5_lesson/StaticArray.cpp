#include "StaticArray.h"
#include <sstream>

namespace cls{
	template<int size>
	string toString(StaticArray<char, size>& array) {
		std::stringstream ss{};
		for (int i{0}; i < size; i++)
			ss << array[i] << " ";
		return ss.str();
	}

	template<class T, int size>
	string toString(StaticArray<T, size>& array) {
		std::stringstream ss{};
		for (int i{0}; i < size; i++)
			ss << array[i] << " ";
		return ss.str();
	}

	template<class T, int size>
	string StaticArray<T, size>::toString() const {
		std::stringstream ss{};
		for (int i{0}; i < size; i++)
			ss << mArray[i] << " ";
		return ss.str();
	}

	template<class T, int size>
	T& StaticArray<T, size>::operator[](int index) {
		return mArray[index];
	}

	template<class T, int size>
	T* StaticArray<T, size>::getArray() {
		return mArray;
	}
}
