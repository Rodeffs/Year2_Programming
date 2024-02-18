#pragma once
namespace arrutls {

	template <class T>
	class ArrayUtils {
	public:
		ArrayUtils() = delete;
		static T average(T* array, int len);  // static указывает на то, что нам не нужно создавать элемент этого класса для вызова данного метода
	};
}
