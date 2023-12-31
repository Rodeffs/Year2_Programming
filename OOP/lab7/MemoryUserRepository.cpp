#include "MemoryUserRepository.h"

MemoryUserRepository::MemoryUserRepository(const vector<User*>& repo) {
	this->repo = repo;
}

MemoryUserRepository::~MemoryUserRepository() {
	for (int i = 0; i < this->repo.size(); i++)
		delete this->repo[i];
	this->repo.clear();
}

User* MemoryUserRepository::getById(int id) {
	for (int i = 0; i < this->repo.size(); i++) {
		if (this->repo[i]->getId() == id)
			return this->repo[i];
	}
	return nullptr;
}

User* MemoryUserRepository::getByName(const string& name) {
	for (int i = 0; i < this->repo.size(); i++) {
		if (this->repo[i]->getName() == name)
			return this->repo[i];
	}
	return nullptr;
}

User* MemoryUserRepository::getByEmail(const string& email) {
	for (int i = 0; i < this->repo.size(); i++) {
		if (this->repo[i]->getEmail() == email)
			return this->repo[i];
	}
	return nullptr;
}

vector<User*> MemoryUserRepository::getByCity(const string& city) {
	vector<User*> returnVec;
	for (int i = 0; i < this->repo.size(); i++) {
		if (this->repo[i]->getCity() == city)
			returnVec.push_back(this->repo[i]);
	}
	return returnVec;
}

vector<User*> MemoryUserRepository::getByGender(Gender gender) {
	vector<User*> returnVec;
	for (int i = 0; i < this->repo.size(); i++) {
		if (this->repo[i]->getGender() == gender)
			returnVec.push_back(this->repo[i]);
	}
	return returnVec;
}
