/* Задание, орфография от автора:

Создаем класс шаблонный Arry3d<> который хранит одномерный массив, гно авдыает наружу его как трезхмерные. Переопрделеить операти=оры индексации [][][], <<
Сдлать методы GetValue0(int i) ->[][] GeValue1(int j) ->[][]  GetValues2(int k) -> [][]
GetValues01(int i, int j) -> []
GetValues02(int i, int k) ->[]
GetValues12(in j, int k) -> []
и аналогичные методы для SetValues
Сделать статический метод CrteaeFill для создания массива и присваивания всех элементов одному значению

*/


// ВАЖНО: см. explanation.png для пояснения того, как из 3-мерного массива сделать одномерный и как мы обходим список по индексам. Стоит отметить, что в том списке, что указан в примере, могут быть абсолютно разные элементы, важен лишь их индекс и размерность каждой координаты

/* НУЖНО СДЕЛАТЬ:
 * Сделать так, чтобы метод возвращал многомерный массив, см. https://www.geeksforgeeks.org/cpp-return-2d-array-from-function/
 * */

#pragma once

#include <vector>  // невозможно создать статический массив произвольной длины и потом ещё его как-то вернуть
#include <iostream>

using std::vector;
using std::ostream;

namespace Arrays {

	template <class T>
	class Array3D {
	private:
		int m_dim0{}, m_dim1{}, m_dim2{};
		vector<T> array3d;

	public:
		explicit Array3D(int dim0, int dim1, int dim2) : m_dim0{dim0}, m_dim1{dim1}, m_dim2{dim2} {}

		explicit Array3D(const vector<T> &array, int dim0, int dim1, int dim2) : m_dim0{dim0}, m_dim1{dim1}, m_dim2{dim2} {}

		vector<vector<T>> getValues0(int i);

		vector<vector<T>> getValues1(int j);

		vector<vector<T>> getValues2(int k);

		vector<T> getValues01(int i, int j);

		vector<T> getValues02(int i, int k);

		vector<T> getValues12(int j, int k);

		void setValues0(const vector<vector<T>> &arr12, int i);

		void setValues1(const vector<vector<T>> &arr02, int j);

		void setValues2(const vector<vector<T>> &arr01, int k);

		void setValues01(const vector<T> &arr2, int k);

		void setValues02(const vector<T> &arr1, int j);

		void setValues12(const vector<T> &arr0, int i);

		void createFill(T x);

		int size();

		T& operator[](int i);

		friend ostream& operator<<(ostream& stream, const Array3D<T>& array);
	};
}
