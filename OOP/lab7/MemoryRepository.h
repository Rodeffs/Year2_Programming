#include "IRepository.h"

template <class T>
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
			if (this->repo[i] == item) {
				this->repo[i] = item;
				break;
			}
	}

	void Delete(T* item) override {
		for (int i = 0; i < this->repo.size(); i++)
			if (this->repo[i] == item) {
				delete this->repo[i];
				this->repo.erase(this->repo.begin()+i);
				break;
			}
	}

	vector<T*>& Get() override {
		return this->repo;
	}
};

