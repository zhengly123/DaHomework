#pragma once
#ifndef LOAD_STRATEGY_H
#define LOAD_STRATEGY_H
#include <fstream>
#include"dict.h"
//加载词典文件
class LoadStrategy
{
public:
	LoadStrategy();
	//禁止复制
	//LoadStrategy(const LoadStrategy &orig) = delete;
	virtual ~LoadStrategy();
	//加载词典文件
	virtual const Dict Load(const std::string &path) = 0;
};



#endif  // !LOAD_STRATEGY_H
