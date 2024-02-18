#pragma once

#include "IRepository.h"
#include "User.h"

class IUserRepository : virtual public IRepository<User> {  // virtual необходимо прописывать, чтобы не возникало так называемой проблемы алмаза
public:
	IUserRepository() = default;

	virtual ~IUserRepository() = default;

	virtual User* getById(int id) = 0;

	virtual User* getByName(const string& name) = 0;

	virtual User* getByEmail(const string& email) = 0;

	virtual vector<User*> getByCity(const string& city) = 0;

	virtual vector<User*> getByGender(Gender gender) = 0;
};
