#include "MemoryRepository.h"
#include "MemoryRepository.cpp"
#include "User.h"

template vector<User*>& MemoryRepository<User>::Get(); 
