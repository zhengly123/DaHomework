#pragma once
#ifndef LOGGER_JSON_H
#define LOGGER_JSON_H
#include"logger.h"
const std::string JUsername = "Username";
const std::string JPassword = "Password";
class LoggerJson
	:public Logger
{
public:
	using Logger::Logger;
	virtual ~LoggerJson();
private:
	virtual bool load_user_list(UserListType &user_list) override;
	virtual bool save_user_list(const UserListType &user_list) override;
};




#endif  // !LOGGER_JSON_H