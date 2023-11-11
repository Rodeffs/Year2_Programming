#include "StaticArray.h"
#include "StaticArray.cpp"

// Этот файл нужен для создания шаблонов, иначе не скомпилируется

template class cls::StaticArray<int, 14>;

template class cls::StaticArray<char, 15>;
template string cls::toString(StaticArray<char, 15>& array);
