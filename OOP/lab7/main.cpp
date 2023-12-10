#include "User.h"
#include "MemoryUserRepository.h"

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
	
		
	return 0;
}
