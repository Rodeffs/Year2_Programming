#pragma once

#include <string>

using std::string;

namespace cls {

	template <class T, int size>
	class StaticArray {
	private:
		T mArray[size];

	public:
		StaticArray() = default;

		[[nodiscard]] T* getArray();

		T& operator[](int index);

		string toString() const;

		virtual ~StaticArray() = default;
	};

	template <class T, int size>
	string toString(StaticArray<T, size>& array);

	template <int size>
	string toString(StaticArray<char, size>& array);
}
