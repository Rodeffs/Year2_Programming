#include "StaticArray.h"
#include <iostream>
#include <cmath>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

/*
template<int number>
double sqrt2() {
	static_assert(number >= 0);
	return std::sqrt(number);
}
*/

int main() {
	
	// int value;
	// std::cin >> value;
	// const int size = 12 / value; - такое возможно для const, но не для constexpr, т.к. он не может зависеть от переменных, значение которых мы не знаем при компиляции

	/*	
	constexpr int size = 12;
	int array[size]{};
	sqrt2<-5>();
	*/

	using namespace cls;

	StaticArray<int, 14> int14{};

	for (int i = 0; i < 14; i++)
		int14[i] = 10 * i;

	cout << int14.toString() << endl;


	StaticArray<char, 15> char15{};

	string message = "Hello, world!";
	message.copy(char15.getArray(), 15);

	cout << toString(char15) << endl;

	return 0;
}

