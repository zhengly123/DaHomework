#include "logger.h"



Logger::Logger(std::string path)
	:path_(path)
{
}


Logger::~Logger()
{
}

bool Logger::Login(const User user)
{
	for (const auto &i : user_list_)
		if (i == user)
			return true;
	return false;
}

bool Logger::Signup(const User user)
{
	for (const auto &i : user_list_)
		if (user == i)
			return false;
	user_list_.push_back(user);
	return save_user_list(user_list_);
}

bool Logger::Load()
{
	return load_user_list(user_list_);
}

