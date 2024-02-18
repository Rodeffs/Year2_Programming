#include "ComplexNumber.h"

using namespace Data;

ComplexNumber::ComplexNumber(double real, double imag) : real{real}, imag{imag} { // инициализация
}

ComplexNumber::ComplexNumber(const ComplexNumber& complex) {} // конструктор копирования, передаём по ссылке для экономии памяти, const означает, что поменять в нём ничего не сможем, если скопировали

ComplexNumber::~ComplexNumber() {}

double ComplexNumber::getReal() const { // нужно делать их константными методами, иначе нет гарантии, что при передаче по ссылке вызовется именно этот метод
	return this->real;
}

double ComplexNumber::getImaginary() const {
	return this->imag;
}

double ComplexNumber::getModulus() const {
	return sqrt(pow(this->real, 2)+pow(this->imag, 2)); 
}

void ComplexNumber::setReal(double real) {
	this->real = real;
}

void ComplexNumber::setImaginary(double imag) {
	this->imag = imag;
}

bool ComplexNumber::operator==(const ComplexNumber& number) {
	return this->getModulus() == number.getModulus();
}

bool ComplexNumber::operator!=(const ComplexNumber& number) {
	return this->getModulus() != number.getModulus();
}

bool ComplexNumber::operator>(const ComplexNumber& number) {
	return this->getModulus() > number.getModulus();
}

bool ComplexNumber::operator>=(const ComplexNumber& number) {
	return this->getModulus() >= number.getModulus();
}

bool ComplexNumber::operator<(const ComplexNumber& number) {
	return this->getModulus() < number.getModulus();
}

bool ComplexNumber::operator<=(const ComplexNumber& number) {
	return this->getModulus() <= number.getModulus();
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& complex) {
	return ComplexNumber{this->real + complex.getReal(), this->imag + complex.getImaginary()};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& complex) {
	return ComplexNumber{this->real - complex.getReal(), this->imag - complex.getImaginary()};
}

ComplexNumber& ComplexNumber::operator=(double real) {
	this->real = real;
	return *this;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& complex) {
	this->real += complex.real;
	this->imag += complex.imag;
}

ComplexNumber& ComplexNumber::operator/(double real) {
	this->real /= real;
	this->imag /= real;
}
std::ostream& Data::operator<<(std::ostream& stream, const ComplexNumber& number) { // здесь уже нужно написать конкретно из какого namespace взять этот оператор
	stream << number.real << "; " << number.imag << "i";
	return stream;	
}
