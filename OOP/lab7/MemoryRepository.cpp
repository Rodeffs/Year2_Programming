#include "MemoryRepository.h"

template <class T>
MemoryRepository<T>::~MemoryRepository() {
	for (int i = 0; i < this->repo.size(); i++)
		delete this->repo[i];
}

template <class T>
void MemoryRepository<T>::Add(T* item) {
	this->repo.push_back(item);	
}

template <class T>
void MemoryRepository<T>::Update(T* item) {
	for (int i = 0; i < this->repo.size(); i++)
		if (this->repo[i] == item) {
			this->repo[i] = item;
			break;
		}
}

template <class T>
void MemoryRepository<T>::Delete(T* item) {
	for (int i = 0; i < this->repo.size(); i++)
		if (this->repo[i] == item) {
			this->repo.erase(i);
			break;
		}
}

template <class T>
vector<T*>& MemoryRepository<T>::Get() {
	return this->repo;
}

