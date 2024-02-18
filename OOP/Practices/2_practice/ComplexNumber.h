#pragma once
#include <iostream>

namespace nmb {
	class ComplexNumber {
	public:
		ComplexNumber(double real = 0, double imag = 0);

		double getReal() const;
		void setReal(double real);

		double getImaginary() const;
		void setImaginary(double imag);
		
		ComplexNumber& operator+=(const ComplexNumber& number);
		ComplexNumber operator/(int number);

		friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& number);
	private:
		double mReal;
		double mImag;
	};
}
