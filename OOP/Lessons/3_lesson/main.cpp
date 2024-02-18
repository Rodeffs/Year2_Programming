#include "ComplexNumber.h"
using std::cin, std::cout, std::endl;

template <typename T>  // шаблон
T sum(T a, T b);

template <class T>
T average(T* array, int len_arr);

int main() {

	using namespace Data;		

	auto number1 = ComplexNumber{2, 3.4};
	auto number2 = ComplexNumber{1.4, 2.2};

	ComplexNumber number3 = 4;

	auto number4 = number1 + number2;

	auto res = sum(2, 3);

	double array1[] = {593, 9.4, 57.6, 42};
	auto avg = average(array1, sizeof(array1));

	ComplexNumber array2[] = {ComplexNumber{2.3, 4.5}, ComplexNumber{4.7, 1.2}, ComplexNumber{3.2, -2.3}, ComplexNumber{-10.6, 22.4}};
	auto avg2 = average(array2, sizeof(array2));

	return 0;
}

template <typename T>
T sum(T a, T b) {
	return a + b;
}

template <class T>
T average(T* array, int len_arr) {

	T sum{};
	for (int i = 0; i < len_arr; i++)
		sum += array[i];

	return sum / len_arr;
}
