#pragma once
#ifndef LOAD_DICT_STRATEGY_H
#define LOAD_DICT_STRATEGY_H
#include <fstream>
#include"dict.h"
//加载词典文件
class LoadDictStrategy
{
public:
	LoadDictStrategy();
	//禁止复制
	LoadDictStrategy(const LoadDictStrategy &orig) = delete;
	virtual ~LoadDictStrategy();
	//加载词典文件
	virtual const Dict Load(const std::string &path) = 0;
};



#endif  // !LOAD_DICT_STRATEGY_H
