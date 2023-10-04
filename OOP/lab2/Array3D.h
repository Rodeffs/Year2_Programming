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

namespace Arrays {

	template <class T>
	class Array3D {
	private:
		int m_dim0{}, m_dim1{}, m_dim2{};  // размерности по i, j и k соответственно
		int N;  // величина массива, чтобы не пришлось пересчитывать
		T* array3d[];

	public:
		Array3D(int dim0, int dim1, int dim2) : m_dim0{dim0}, m_dim1{dim1}, m_dim2{dim2} {
			N = dim0 * dim1 * dim2;
			T array[N];
			*array3d = array;	
		}

		T getValues0(int i) {  // возвращает значения в i строке (плоскость Oyz)
			T returnArr[m_dim2][m_dim1];
			int y{0}, step{m_dim0 * m_dim1};
			for (int k = i * step; k < N; k += step) {
				for (int j = 0; j < m_dim1; j++)
					returnArr[y][j] = array3d[k+j];
				y++;
			}
			return returnArr;
		}

		T getValues1(int j) {  // возвращает значения в j столбце (плоскость Oxz)
			T returnArr[m_dim2][m_dim0];
			int i{j};
			for (int k = 0; k < m_dim2; k++)
				for (int x = 0; x < m_dim0; x++) {
					returnArr[k][x] = array3d[i];
					i += m_dim1;
				}
			return returnArr;
		}
		
		T getValues2(int k) { // возвращает значения в k слое (плоскость Oxy)
			T returnArr[m_dim1][m_dim0];
			int t{0};
			for (int j = 0; j < m_dim1; j++)
				for (int i = 0; i < m_dim0; i++) {
					returnArr[j][i] = array3d[k * m_dim0 * m_dim1 + t];
					t++;
				}
			return returnArr;
		}

		T getValues01(int i, int j) {  // возвращает значения в оси аппликат (для k)
			T returnArr[m_dim2];
			int x{0};
			for (int k = i * m_dim0; k < N; k += m_dim0 * m_dim1) { 
				returnArr[x] = array3d[k + j];
		      		x++;	
			}
			return returnArr;
		}

		T getValues02(int i, int k) {
			T returnArr[m_dim1];
			for (int j = 0; j < m_dim1; j++)
				returnArr[j] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
			return returnArr;
		}

		T getValues12(int j, int k) {
			T returnArr[m_dim0];
			for (int i = 0; i < m_dim0; i += 1)
				returnArr[i] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
			return returnArr;
		}

		void setValues0(int *arr12[]) {

		}
			
		void setValues1(int *arr02);
		
		void setValues2(int *arr01);

		void setValues01(int *arr, int j);

		void setValues02(int i, int k);

		void setValues12(int j, int k);

		void createFill(T x) {
			T array[N] = {x};
			*array3d = array;
		}

	};
}
