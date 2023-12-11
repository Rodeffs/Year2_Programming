#pragma once

#include <vector>

using std::vector;

template <class T>
class IRepository {
protected:
	vector<T*> repo;

public:
	IRepository() = default;

	virtual ~IRepository() = default;

	virtual void Add(T* item) = 0;

	virtual void Update(T* item) = 0;

	virtual void Delete(T* item) = 0;

	virtual vector<T*>& Get() = 0; // т.к. T - элемент произвольной природы, то неизвестно, как организовать поиск по полю where и orderBy, поэтому Get() просто весь вектор вернёт
};
