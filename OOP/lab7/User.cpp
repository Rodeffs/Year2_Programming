#include "User.h"

int User::getId() {
	return this->id;
}

void User::setId(int id) {
	this->id = id;
}

string& User::getName() {
	return this->name;
}

void User::setName(const string& name) {
	this->name = name;
}

string& User::getEmail() {
	return this->email;
}

void User::setEmail(const string& email) {
	this->email = email;
}

string& User::getPhone() {
	return this->phone;
}

void User::setPhone(const string& phone) {
	this->phone = phone;
}

string& User::getCity() {
	return this->city;
}

void User::setCity(const string& city) {
	this->city = city;
}

Gender User::getGender() {
	return this->gender;
}

void User::setGender(Gender gender) {
	this->gender = gender;
}

bool User::operator==(User& other) {
	return this->getId() == other.getId();  // т.к. у каждого пользователя уникальный id, который после установки по идее не должен меняться, то проверка будет именно по нему,
}

User& User::operator=(User& other) {
	this->id = other.getId();
	this->name = other.getName();
	this->email = other.getEmail();
	this->phone = other.getPhone();
	this->city = other.getCity();
	this->gender = other.getGender();
	return *this;
}
