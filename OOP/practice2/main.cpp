#include "ArrayUtils.h"
#include <iostream>
#include "ComplexNumber.h"

int main() {
	
	int numbers[]{1, 2, 3, 4, 5, 56, 23};
      	int numbersLen{std::size(numbers)};  // size() для того, чтобы посчитать размер массива
	
	auto avg = arrutls::ArrayUtils<int>::average(numbers, numbersLen);
	std::cout << "Average value: " << avg << std::endl;

	using namespace nmb;

	ComplexNumber complexNumbers[] {
		ComplexNumber{1, -3.4},
		ComplexNumber{1.5, 2.1},
		ComplexNumber{8.7, 1.2},
	};

	int complexNumbersLen{ std::size(complexNumbers) };
	auto avgComplex = arrutls::average(complexNumbers, complexNumbersLen);
	std::cout << "Average complex number: " << avgComplex << std::endl;
}
