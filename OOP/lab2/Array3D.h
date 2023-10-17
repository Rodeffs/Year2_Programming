#pragma once

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
 * 1) Вывести реализацию и шаблон в отдельные файлы, см. practice2
 * 2) Сделать так, чтобы метод возвращал многомерный массив, см. https://www.geeksforgeeks.org/cpp-return-2d-array-from-function/
 * */

namespace Arrays {

	template <class T>
	class Array3D {
	private:
		int m_dim0{}, m_dim1{}, m_dim2{};  // размерности по i, j и k соответственно
		int N;  // величина массива, чтобы не пришлось пересчитывать
		T* array3d;

	public:
		Array3D(int dim0, int dim1, int dim2) : m_dim0{dim0}, m_dim1{dim1}, m_dim2{dim2} {
			N = dim0 * dim1 * dim2;
			T array[N];
			array3d = array;	
		}

		~Array3D() {
			delete[] array3d;
		}

		T* getValues0(int i) {  // возвращает значения в i строке (плоскость Oyz)
			T returnArr[m_dim2][m_dim1];
			int y{0}, step{m_dim0 * m_dim1};
			for (int k = i * step; k < N; k += step) {
				for (int j = 0; j < m_dim1; j++)
					returnArr[y][j] = array3d[k+j];
				y++;
			}
			return returnArr;
		}

		T* getValues1(int j) {  // возвращает значения в j столбце (плоскость Oxz)
			T returnArr[m_dim2][m_dim0];
			int i{j};
			for (int k = 0; k < m_dim2; k++)
				for (int x = 0; x < m_dim0; x++) {
					returnArr[k][x] = array3d[i];
					i += m_dim1;
				}
			return returnArr;
		}
		
		T* getValues2(int k) { // возвращает значения в k слое (плоскость Oxy)
			T returnArr[m_dim1][m_dim0];
			int t{0};
			for (int j = 0; j < m_dim1; j++)
				for (int i = 0; i < m_dim0; i++) {
					returnArr[j][i] = array3d[k * m_dim0 * m_dim1 + t];
					t++;
				}
			return returnArr;
		}

		T* getValues01(int i, int j) {  // возвращает значения в оси аппликат (для k)
			T returnArr[m_dim2];
			int x{0};
			for (int k = i * m_dim0; k < N; k += m_dim0 * m_dim1) { 
				returnArr[x] = array3d[k + j];
		      		x++;	
			}
			return returnArr;
		}

		T* getValues02(int i, int k) {  // возвращает значения в оси ординат (для j)
			T returnArr[m_dim1];
			for (int j = 0; j < m_dim1; j++)
				returnArr[j] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
			return returnArr;
		}

		T* getValues12(int j, int k) {  // возвращает значения в оси абсцисс (для i)
			T returnArr[m_dim0];
			for (int i = 0; i < m_dim0; i += 1)
				returnArr[i] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
			return returnArr;
		}

		void setValues0(int *arr12, int i) {  // устанавливает значения для плоскости, проходящей через абсциссу i
			for (int j = 0; j < m_dim1; j++) {
				int temp[m_dim2] = arr12[j];  // по другому 2-мерный список не передать
				for (int k = 0; k < m_dim2; k++)
					array3d[k * m_dim0 * m_dim1 + i + j] = temp[k];
			}
		}
			
		void setValues1(int *arr02, int j) {  // устанавливает значения для плоскости, проходящей через ординату j
			for (int i = 0; i < m_dim0; i++) {
				int temp[m_dim2] = arr02[i];
				for (int k = 0; k < m_dim2; k++)
					array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j] = temp[k];
			}
		}
		
		void setValues2(int *arr01, int k) {  // устанавливает значения для плоскости, проходящей через аппликату k 
			for (int i = 0; i < m_dim0; i++) {
				int temp[m_dim1] = arr01[i];
				for (int j = 0; j < m_dim1; j++)
					array3d[i * m_dim1 + j * m_dim1 + k * m_dim0 * m_dim1] = temp[j];
			}
		}

		void setValues01(int *arr2, int k) {  // устанавливает значения для k координаты
			for (int x = 0; x < m_dim2; x++)
				array3d[k * m_dim0 * m_dim1 + x] = arr2[x];	
		}

		void setValues02(int *arr1, int j) {  // устанавливает значения для j координаты
			for (int x = 0; x < m_dim1; x++)
				array3d[x * m_dim1 + j] = arr1[x];
		}

		void setValues12(int *arr0, int i) {  // устанавливает значения для i координаты
			int t{0};
			for (int y = i * m_dim1; y < N; y += m_dim0 * m_dim1)
				for (int x = 0; x < m_dim1; x++) {
					array3d[y + x] = arr0[t];
					t++;
				}
		}

		void createFill(T x) {
			for (int y = 0; y < N; y++)
				array3d[y] = x;
		}

	};
}
