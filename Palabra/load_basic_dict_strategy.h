#pragma once
#ifndef LOAD_BASIC_DICT_STRATEGY_H
#define LOAD_BASIC_DICT_STRATEGY_H
#include <fstream>
#include"basic_dict.h"
//加载词典文件
class LoadBasicDictStrategy
{
public:
	LoadBasicDictStrategy();
	//禁止复制
	LoadBasicDictStrategy(const LoadBasicDictStrategy &orig) = delete;
	virtual ~LoadBasicDictStrategy();
	//加载词典文件
	virtual const BasicDict Load(const std::string &path) = 0;
};



#endif  // !LOAD_BASIC_DICT_STRATEGY_H
