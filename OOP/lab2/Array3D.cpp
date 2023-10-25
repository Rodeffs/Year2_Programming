#include "Array3D.h"

using namespace Arrays;

template <class T>
Array3D<T>::Array3D(int dim0, int dim1, int dim2) : m_dim0{dim0}, m_dim1{dim1}, m_dim2{dim2} {
	N = m_dim0 * m_dim1 * m_dim2;
	T array[N];
	*array3d = array;	
}

template <class T>
Array3D<T>::~Array3D() {
	delete[] array3d;
}

template <class T>
MultiArray<T>* Array3D<T>::getValues0(int i) {  // возвращает значения в i строке (плоскость Oyz)
	T returnArr[m_dim2][m_dim1];
	int y{0}, step{m_dim0 * m_dim1};
	for (int k = i * step; k < N; k += step) {
		for (int j = 0; j < m_dim1; j++)
			returnArr[y][j] = array3d[k+j];
		y++;
	}
	auto multiArr = new MultiArray<T>;
	std::copy(multiArr->array, multiArr->array + m_dim2, returnArr);
	return multiArr;
}

template <class T>
MultiArray<T>* Array3D<T>::getValues1(int j) {  // возвращает значения в j столбце (плоскость Oxz)
	T returnArr[m_dim2][m_dim0];
	int i{j};
	for (int k = 0; k < m_dim2; k++)
		for (int x = 0; x < m_dim0; x++) {
			returnArr[k][x] = array3d[i];
			i += m_dim1;
		}

	auto multiArr = new MultiArray<T>;
	std::copy(multiArr->array, multiArr->array + m_dim2, returnArr);
	return multiArr;
}

template <class T>
MultiArray<T>* Array3D<T>::getValues2(int k) { // возвращает значения в k слое (плоскость Oxy)
	T returnArr[m_dim1][m_dim0];
	int t{0};
	for (int j = 0; j < m_dim1; j++)
		for (int i = 0; i < m_dim0; i++) {
			returnArr[j][i] = array3d[k * m_dim0 * m_dim1 + t];
			t++;
		}
	auto multiArr = new MultiArray<T>;
	std::copy(multiArr->array, multiArr->array + m_dim1, returnArr);
	return multiArr;
}

template <class T>
T* Array3D<T>::getValues01(int i, int j) {  // возвращает значения в оси аппликат (для k)
	T* returnArr = new T[m_dim2];
	int x{0};
	for (int k = i * m_dim0; k < N; k += m_dim0 * m_dim1) { 
		returnArr[x] = array3d[k + j];
		x++;	
	}
	return returnArr;
}

template <class T>
T* Array3D<T>::getValues02(int i, int k) {  // возвращает значения в оси ординат (для j)
	T* returnArr = new T[m_dim1];
	for (int j = 0; j < m_dim1; j++)
		returnArr[j] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
	return returnArr;
}

template <class T>
T* Array3D<T>::getValues12(int j, int k) {  // возвращает значения в оси абсцисс (для i)
	T* returnArr = new T[m_dim0];
	for (int i = 0; i < m_dim0; i += 1)
		returnArr[i] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
	return returnArr;
}

template <class T>
void Array3D<T>::setValues0(MultiArray<T>* arr12, int i) {  // устанавливает значения для плоскости, проходящей через абсциссу i	
	for (int j = 0; j < m_dim1; j++) {
		int temp[m_dim2];
		std::copy((*arr12).array[j], (*arr12).array[j] + m_dim2, temp);  // по другому 2-мерный список не передать
		for (int k = 0; k < m_dim2; k++)
			array3d[k * m_dim0 * m_dim1 + i + j] = temp[k];
	}
}
	
template <class T>
void Array3D<T>::setValues1(MultiArray<T>* arr02, int j) {  // устанавливает значения для плоскости, проходящей через ординату j
	for (int i = 0; i < m_dim0; i++) {
		int temp[m_dim2];
		std::copy((*arr02).array[i], (*arr02).array[i] + m_dim2, temp);
		for (int k = 0; k < m_dim2; k++)
			array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j] = temp[k];
	}
}

template <class T>
void Array3D<T>::setValues2(MultiArray<T>* arr01, int k) {  // устанавливает значения для плоскости, проходящей через аппликату k 
	for (int i = 0; i < m_dim0; i++) {
		int temp[m_dim1];
		std::copy((*arr01).array[i], (*arr01).array[i] + m_dim2, temp);
		for (int j = 0; j < m_dim1; j++)
			array3d[i * m_dim1 + j * m_dim1 + k * m_dim0 * m_dim1] = temp[j];
	}
}

template <class T>
void Array3D<T>::setValues01(T* arr2, int k) {  // устанавливает значения для k координаты
	for (int x = 0; x < m_dim2; x++)
		array3d[k * m_dim0 * m_dim1 + x] = *arr2[x];	
}

template <class T>
void Array3D<T>::setValues02(T* arr1, int j) {  // устанавливает значения для j координаты
	for (int x = 0; x < m_dim1; x++)
		array3d[x * m_dim1 + j] = *arr1[x];
}

template <class T>
void Array3D<T>::setValues12(T* arr0, int i) {  // устанавливает значения для i координаты
	int t{0};
	for (int y = i * m_dim1; y < N; y += m_dim0 * m_dim1)
		for (int x = 0; x < m_dim1; x++) {
			array3d[y + x] = *arr0[t];
			t++;
		}
}

template <class T>
void Array3D<T>::createFill(T x) {
	for (int y = 0; y < N; y++)
		array3d[y] = x;
}
