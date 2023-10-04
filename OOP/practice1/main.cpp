#include "ComplexNumber.h"
using std::cin, std::cout, std::endl;


int main() {
	
	Data::ComplexNumber complex1{};
	Data::ComplexNumber complex2{2.0};
	Data::ComplexNumber complex3{3.0, 5.0};
	Data::ComplexNumber complex4{complex3}; // копирующий конструктор

	auto complex5 = complex2 + complex3; // такое работает только при перегрузке оператора

	cout << complex5 << endl;

	cout << "Hello, world!" << endl;

	return 0;
}
