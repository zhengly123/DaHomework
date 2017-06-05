#include "user.h"

User::User()
{
}

User::User(const std::string username, const std::string password)
	:username_(username), password_(password)
{
}


User::~User()
{
}
