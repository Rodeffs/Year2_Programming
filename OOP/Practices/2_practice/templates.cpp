#include "ArrayUtils.h"
#include "ArrayUtils.cpp"
#include "ComplexNumber.h"

// В этом файле мы прописываем отдельную реализацию шаблона для каждого типа, иначе будет ошибка линковки
// Вынесли в отдельный файл, чтобы не зависеть от классов
template int arrutls::ArrayUtils<int>::average(int* array, int len);
template nmb::ComplexNumber arrutls::ArrayUtils<nmb::ComplexNumber>::average(nmb::ComplexNumber* array, int len);
template double arrutls::ArrayUtils<double>::average(double* array, int len);
