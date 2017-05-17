#include<fstream>
#include "logger_simple.h"
const std::string user_path = "user_simple.ini";
LoggerSimple::LoggerSimple()
{
	std::ifstream is(user_path);
	//std::string username, password;
	User user;
	while (is >> user.username_ >> user.password_)
		user_list_.push_back(user);
}


LoggerSimple::~LoggerSimple()
{
}

bool LoggerSimple::Login(const User &user)
{
	for (auto i : user_list_)
		if (i == user)
			return true;
	return false;
}

bool LoggerSimple::Signup(const User &user)
{
	//TODO: uncode
	return false;
}
