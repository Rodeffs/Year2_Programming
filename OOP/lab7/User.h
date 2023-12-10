#pragma once

#include <string>

using std::string;

enum class Gender {MALE, FEMALE, NEUTRAL};

class User {
private:
	int id;
	string name;
	string email;
	string phone;
	string city;
	Gender gender;

public:
	User(int newId, const string& newName, const string& newEmail, const string& newPhone, const string& newCity, Gender newGender) : id{newId}, name{newName}, email{newEmail}, phone{newPhone}, city{newCity}, gender{newGender} {}

	int getId();

	void setId(int id);

	string& getName();

	void setName(const string& name);

	string& getEmail();

	void setEmail(const string& email);

	string& getPhone();

	void setPhone(const string& phone);

	string& getCity();

	void setCity(const string& city);

	Gender getGender();

	void setGender(Gender gender);

	bool operator==(User& other);

	User& operator=(User& other);
};
