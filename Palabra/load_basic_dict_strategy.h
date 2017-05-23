#pragma once
#ifndef LOAD_BASIC_DICT_STRATEGY_H
#define LOAD_BASIC_DICT_STRATEGY_H
#include <fstream>
#include"basic_dict.h"
//加载基础词典文件的抽象策略类
class LoadBasicDictStrategy
{
public:
	LoadBasicDictStrategy();
	//禁止复制
	LoadBasicDictStrategy(const LoadBasicDictStrategy &orig) = delete;
	virtual ~LoadBasicDictStrategy();
	
	//virtual const BasicDict Load(const std::string &path) = 0;
	//加载词典文件
	virtual bool Load(const std::string & path, BasicDict &dict) = 0;
};



#endif  // !LOAD_BASIC_DICT_STRATEGY_H
