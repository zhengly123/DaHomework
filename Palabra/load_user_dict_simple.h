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
	virtual UserDict Load(const std::string &path) override;
	virtual bool Save(UserDict);
};

#endif  // !LOAD_USERDATA_SIMPLE_H
