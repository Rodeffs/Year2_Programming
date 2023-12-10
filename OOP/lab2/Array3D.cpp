#include "Array3D.h"

using namespace Arrays;

template <class T>
vector<vector<T>> Array3D<T>::getValues0(int i) {  // возвращает значения в i строке (плоскость Oyz)
	vector<vector<T>> returnArr;
	int y{0}, step{m_dim0 * m_dim1};
	for (int k = i * step; k < size(); k += step) {
		for (int j = 0; j < m_dim1; j++)
			returnArr[y][j] = array3d[k+j];
		y++;
	}
	return returnArr;
}

template <class T>
vector<vector<T>> Array3D<T>::getValues1(int j) {  // возвращает значения в j столбце (плоскость Oxz)
	vector<vector<T>> returnArr;
	int i{j};
	for (int k = 0; k < m_dim2; k++)
		for (int x = 0; x < m_dim0; x++) {
			returnArr[k][x] = array3d[i];
			i += m_dim1;
		}

	return returnArr;
}

template <class T>
vector<vector<T>> Array3D<T>::getValues2(int k) { // возвращает значения в k слое (плоскость Oxy)
	vector<vector<T>> returnArr;
	int t{0};
	for (int j = 0; j < m_dim1; j++)
		for (int i = 0; i < m_dim0; i++) {
			returnArr[j][i] = array3d[k * m_dim0 * m_dim1 + t];
			t++;
		}
	return returnArr;
}

template <class T>
vector<T> Array3D<T>::getValues01(int i, int j) {  // возвращает значения в оси аппликат (для k)
	vector<T> returnArr;
	int x{0};
	for (int k = i * m_dim0; k < size(); k += m_dim0 * m_dim1) { 
		returnArr[x] = array3d[k + j];
		x++;	
	}
	return returnArr;
}

template <class T>
vector<T> Array3D<T>::getValues02(int i, int k) {  // возвращает значения в оси ординат (для j)
	vector<T> returnArr;
	for (int j = 0; j < m_dim1; j++)
		returnArr[j] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
	return returnArr;
}

template <class T>
vector<T> Array3D<T>::getValues12(int j, int k) {  // возвращает значения в оси абсцисс (для i)
	vector<T> returnArr;
	for (int i = 0; i < m_dim0; i += 1)
		returnArr[i] = array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j];
	return returnArr;
}

template <class T>
void Array3D<T>::setValues0(const vector<vector<T>> &arr12, int i) {  // устанавливает значения для плоскости, проходящей через абсциссу i	
	for (int j = 0; j < m_dim1; j++) 
		for (int k = 0; k < m_dim2; k++)
			array3d[k * m_dim0 * m_dim1 + i + j] = arr12[j][k];
}
	
template <class T>
void Array3D<T>::setValues1(const vector<vector<T>> &arr02, int j) {  // устанавливает значения для плоскости, проходящей через ординату j
	for (int i = 0; i < m_dim0; i++) 
		for (int k = 0; k < m_dim2; k++)
			array3d[k * m_dim0 * m_dim1 + i * m_dim1 + j] = arr02[i][k];
}

template <class T>
void Array3D<T>::setValues2(const vector<vector<T>> &arr01, int k) {  // устанавливает значения для плоскости, проходящей через аппликату k 
	for (int i = 0; i < m_dim0; i++) 
		for (int j = 0; j < m_dim1; j++)
			array3d[i * m_dim1 + j * m_dim1 + k * m_dim0 * m_dim1] = arr01[i][j];
}

template <class T>
void Array3D<T>::setValues01(const vector<T> &arr2, int k) {  // устанавливает значения для k координаты
	for (int x = 0; x < m_dim2; x++)
		array3d[k * m_dim0 * m_dim1 + x] = arr2[x];	
}

template <class T>
void Array3D<T>::setValues02(const vector<T> &arr1, int j) {  // устанавливает значения для j координаты
	for (int x = 0; x < m_dim1; x++)
		array3d[x * m_dim1 + j] = arr1[x];
}

template <class T>
void Array3D<T>::setValues12(const vector<T> &arr0, int i) {  // устанавливает значения для i координаты
	int t{0};
	for (int y = i * m_dim1; y < size(); y += m_dim0 * m_dim1)
		for (int x = 0; x < m_dim1; x++) {
			array3d[y + x] = arr0[t];
			t++;
		}
}

template <class T>
void Array3D<T>::createFill(T x) {
	for (int y = 0; y < size(); y++)
		array3d[y] = x;
}

template <class T>
T& Array3D<T>::operator[](int i) {
	return array3d[i];
}

template <class T>
int Array3D<T>::size() {
	return array3d.size();
}

template <class T>
ostream& operator<<(ostream& stream, const Array3D<T> &array) {
	for (int i = 0; i < array.size(); i++)
		stream << array[i] << " ";
	return stream;
}
