#include "ComplexNumber.h"

using namespace nmb;

ComplexNumber::ComplexNumber(double real, double imag) : mReal{real}, mImag{imag} {}

double ComplexNumber::getReal() const {
	return mReal;
}

void ComplexNumber::setReal(double real) {
	mReal = real;
}

double ComplexNumber::getImaginary() const {
	return mImag;
}

void ComplexNumber::setImaginary(double imag) {
	mImag = imag;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& number) {
	mReal += number.mReal;
	mImag += number.mImag;
	return *this;
}
ComplexNumber ComplexNumber::operator/(int number) {
	return ComplexNumber{mReal / number, mImag / number};
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& number) {
	out << "(" << number.mReal << ", " << number.mImag << ")";
	return out;
}
