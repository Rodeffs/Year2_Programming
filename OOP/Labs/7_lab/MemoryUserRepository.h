#pragma once

#include "IUserRepository.h"
#include "MemoryRepository.h"
#include "User.h"

class MemoryUserRepository : public MemoryRepository<User>, virtual public IUserRepository {
public:
	MemoryUserRepository() = default;

	explicit MemoryUserRepository(const vector<User*>& repo);

	~MemoryUserRepository();

	User* getById(int id) override;

	User* getByName(const string& name) override;

	User* getByEmail(const string& email) override;

	vector<User*> getByCity(const string& city) override;

	vector<User*> getByGender(Gender gender) override;
};
