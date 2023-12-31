#include "IRepository.h"

template <class T>  // для шаблонного класса реализацию нужно писать в заголовочном файле, иначе компилятор не знает, какой тип возвращает T и нужно создавать template.cpp, что нецелесообразно в этом случае
class MemoryRepository : virtual public IRepository<T> {
public:
	MemoryRepository() = default;

	~MemoryRepository() {
		for (int i = 0; i < this->repo.size(); i++)
			delete this->repo[i];
		this->repo.clear();
	}

	void Add(T* item) override {
		this->repo.push_back(item);	
	}

	void Update(T* item) override {
		for (int i = 0; i < this->repo.size(); i++)
			if (*(this->repo[i]) == *item) {  // иначе будут сравниваться указатели, а не сами элементы
				delete this->repo[i];
				this->repo.erase(this->repo.begin()+i);
				this->repo.insert(this->repo.begin()+i, item);
				return;
			}
	}

	void Delete(T* item) override {
		for (int i = 0; i < this->repo.size(); i++)
			if (this->repo[i] == item) {
				delete this->repo[i];
				this->repo.erase(this->repo.begin()+i);
				return;
			}
	}

	vector<T*>& Get() override {
		return this->repo;
	}
};

