#pragma once
#include <iostream> // надо здесь подключить эту библиотеку, чтобы перегрузить оператор вывода


namespace Data {
	class ComplexNumber {
	
	public:
		ComplexNumber(double real = 0.0, double imag = 0.0) : real{real}, imag{imag} { // инициализация
		}

		ComplexNumber(const ComplexNumber& complex) {} // конструктор копирования, передаём по ссылке для экономии памяти, const означает, что поменять в нём ничего не сможем, если скопировали

//		ComplexNumber(const ComplexNumber& complex) {} = delete; // запрещаем конструктор копирования 

		double getReal() const { // нужно делать их константными методами, иначе нет гарантии, что при передаче по ссылке вызовется именно этот метод
			return this->real;
		}

		double getImaginary() const {
			return this->imag;
		}

		void setReal(double real) {
			this->real = real;
		}

		void setImaginary(double imag) {
			this->imag = imag;
		}
		
		ComplexNumber add(const ComplexNumber& complex) { // оператор сложения, но лучше перегрузить оператор
//			complex.setReal(4.0); - const запрещает делать такое, таким образом мы его не сможем поменять

			return ComplexNumber{this->real + complex.getReal(), this->imag + complex.getImaginary()};
		}

		ComplexNumber operator+(const ComplexNumber& complex) { // перегрузка оператора

			return ComplexNumber{this->real + complex.getReal(), this->imag + complex.getImaginary()};
		}

		friend std::ostream& operator<<(std::ostream& stream, ComplexNumber& number) { // перегрузка оператора вывода
			stream << number.real << "; " << number.imag << "i";
			return stream;	
		}

	
	private:
		double real{};
		double imag{}; // imaginary part
	};
}
