#pragma once
#ifndef LOAD_USERDATA_STRATEGY_H
#define LOAD_USERDATA_STRATEGY_H
#include<fstream>
#include"user_dict.h"
//加载用户文件
class LoadUserDictStrategy
{
public:
	LoadUserDictStrategy();
	//禁止复制
	LoadUserDictStrategy(const LoadUserDictStrategy&) = delete;
	virtual ~LoadUserDictStrategy();
	//加载词典文件
	virtual UserDict Load(const std::string &path) = 0;
	virtual bool Save(const std::string path, const UserDict& user_dict) = 0;
};

#endif  // !LOAD_USERDATA_STRATEGY_H


