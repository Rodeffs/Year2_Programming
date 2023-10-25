#include "Array3D.h"
#include "Array3D.cpp"
#include "MultiArray.h"

template MultiArray<int>* Arrays::Array3D<int>::getValues0(int i);
template MultiArray<int>* Arrays::Array3D<int>::getValues1(int j);
template MultiArray<int>* Arrays::Array3D<int>::getValues2(int k);
template int* Arrays::Array3D<int>::getValues01(int i, int j);
template int* Arrays::Array3D<int>::getValues02(int i, int k);
template int* Arrays::Array3D<int>::getValues12(int j, int k);

template MultiArray<double>* Arrays::Array3D<double>::getValues0(int i);
template MultiArray<double>* Arrays::Array3D<double>::getValues1(int j);
template MultiArray<double>* Arrays::Array3D<double>::getValues2(int k);
template double* Arrays::Array3D<double>::getValues01(int i, int j);
template double* Arrays::Array3D<double>::getValues02(int i, int k);
