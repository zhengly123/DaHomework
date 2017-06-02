#include "logger_json.h"
#include "json\json.h"
using namespace Json;

LoggerJson::~LoggerJson()
{
}

bool LoggerJson::load_user_list(UserListType &user_list)
{
	std::ifstream is(path_);
	Value root;
	User user;
	is >> root;
	for (const auto &i : root)
	{
		user.username_ = i[JUsername].asString();
		user.password_ = i[JPassword].asString();
		user_list.push_back(user);
	}
	return true;
}

bool LoggerJson::save_user_list(const UserListType &user_list)
{
	std::ofstream os(path_);
	Value root, json_user;
	for (const auto user : user_list)
	{
		json_user[JUsername] = user.username_;
		json_user[JPassword] = user.password_;
		root.append(json_user);
	}
	os << root;
	return true;
}
