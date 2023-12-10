#include "User.h"
#include "MemoryUserRepository.h"
#include <iostream>

using std::cout;
using std::endl;

void output(vector<User*>& items) {
	for (int i = 0; i < items.size(); i++)
		cout << items[i]->getId() << " " 
			<< items[i]->getName() << " " 
			<< items[i]->getEmail() << " " 
			<< items[i]->getPhone() << " " 
			<< items[i]->getCity() << " " 
			<< ((items[i]->getGender() == Gender::MALE) ? "Male" : ((items[i]->getGender() == Gender::FEMALE) ? "Female" : "Neutral")) 
			<< endl;
}

int main() {

	MemoryUserRepository userRepo;

	auto user1 = new User(10, "Alex", "alex@gmail.com", "88005553535", "Moscow", Gender::MALE);
	auto user2 = new User(20, "John", "john@gmail.com", "589305298", "New York", Gender::MALE);
	auto user3 = new User(30, "Rita", "rita@gmail.com", "7589310402", "Moscow", Gender::FEMALE);
	auto user4 = new User(40, "Alice", "alice@gmail.com", "6583492", "London", Gender::FEMALE);
	userRepo.Add(user1);
	userRepo.Add(user2);
	userRepo.Add(user3);
	userRepo.Add(user4);

	auto byCity = userRepo.getByCity("Moscow");
	output(byCity);

	cout << endl;

	userRepo.Delete(user1);
	auto byCity2 = userRepo.getByCity("Moscow");
	output(byCity2);

	cout << endl;

	auto user5 = new User(50, "Sam", "sam@gmail.com", "4984296583492", "Paris", Gender::MALE);
	userRepo.Add(user5);

	auto byGender = userRepo.getByGender(Gender::MALE);
	output(byGender);

	cout << endl;

	auto user6 = userRepo.getById(30);
	cout << user6->getName() << endl;

	return 0;
}
