#pragma once
#ifndef LOAD_USERDATA_SIMPLE_H
#define LOAD_USERDATA_SIMPLE_H
#include<fstream>
#include"load_user_dict_strategy.h"
class LoadUserDictSimple :LoadUserDictStrategy
{
public:
	LoadUserDictSimple();
	virtual ~LoadUserDictSimple();
	//virtual UserDict Load(const std::string &path) override;
	virtual bool Load(const std::string &path, UserDict & dict) override;
	virtual bool Save(const std::string path, const UserDict& user_dict) override;
};

#endif  // !LOAD_USERDATA_SIMPLE_H
