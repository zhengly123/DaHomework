#include<fstream>
#include "logger_simple.h"
const std::string user_path = "user_simple.ini";

LoggerSimple::~LoggerSimple()
{
}

bool LoggerSimple::Login(const User &user)
{
	load_user_list();
	for (const auto &i : user_list_)
		if (i == user)
			return true;
	return false;
}

bool LoggerSimple::Signup(const User &user)
{
	//TODO: uncode
	std::ofstream os(user_path, std::ios::app);
	os << std::endl;
	os << user.username_ << std::endl << user.password_;
	//save_user_list();//
	return true;
}

bool LoggerSimple::load_user_list()
{
	std::ifstream is(user_path);
	//std::string username, password;
	User user;
	while (is >> user.username_ >> user.password_)
		user_list_.push_back(user);
	return true;
}

bool LoggerSimple::save_user_list()
{
	return true;
}
