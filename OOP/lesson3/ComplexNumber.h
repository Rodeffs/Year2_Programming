#pragma once
#include <iostream> // надо здесь подключить эту библиотеку, чтобы перегрузить оператор вывода
#include <cmath>

namespace Data {
	class ComplexNumber {
	
	public:
		ComplexNumber(double real = 0.0, double imag = 0.0);

		ComplexNumber(const ComplexNumber& complex);
		
		virtual ~ComplexNumber();

		double getReal() const;

		double getImaginary() const;
		
		double getModulus() const;

		void setReal(double real); 

		void setImaginary(double imag);

		bool operator==(const ComplexNumber& number);
		bool operator!=(const ComplexNumber& number);
		bool operator>(const ComplexNumber& number);
		bool operator>=(const ComplexNumber& number);
		bool operator<(const ComplexNumber& number);
		bool operator<=(const ComplexNumber& number);
		
		ComplexNumber operator+(const ComplexNumber& complex);
		ComplexNumber operator-(const ComplexNumber& complex);
		ComplexNumber& operator=(double real);
		ComplexNumber& operator+=(const ComplexNumber& complex);
		ComplexNumber& operator/(double real);
		friend std::ostream& operator<<(std::ostream& stream, const ComplexNumber& number);
	
	private:
		double real{};
		double imag{}; // imaginary part
	};
}
