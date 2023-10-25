#pragma once
#include "MultiArray.h"
#include <algorithm>

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

namespace Arrays {

	template <class T>
	class Array3D {
	private:
		int m_dim0{}, m_dim1{}, m_dim2{};  // размерности по i, j и k соответственно
		int N;  // величина массива, чтобы не пришлось пересчитывать
		T* array3d;

	public:
		Array3D(int dim0, int dim1, int dim2);

		~Array3D();

		MultiArray<T>* getValues0(int i);

		MultiArray<T>* getValues1(int j);

		MultiArray<T>* getValues2(int k);

		T* getValues01(int i, int j);

		T* getValues02(int i, int k);

		T* getValues12(int j, int k);

		void setValues0(MultiArray<T>* arr12, int i);

		void setValues1(MultiArray<T>* arr02, int j);

		void setValues2(MultiArray<T>* arr01, int k);

		void setValues01(T* arr2, int k);

		void setValues02(T* arr1, int j);

		void setValues12(T* arr0, int i);

		void createFill(T x);
	};
}
