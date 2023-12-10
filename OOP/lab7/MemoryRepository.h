#include "IRepository.h"

template <class T>
class MemoryRepository : virtual public IRepository<T> {
public:
	MemoryRepository() = default;

	~MemoryRepository();

	void Add(T* item) override;

	void Update(T* item) override;

	void Delete(T* item) override;

	vector<T*>& Get() override;
};
