#include "ArrayUtils.h"
#include "ComplexNumber.h"

template <class T>
T arrutls::ArrayUtils<T>::average(T* array, int len) {
	T sum{};
	for (int i = 0; i < len; i++)
		sum += array[i];
	return sum/len;	
}

