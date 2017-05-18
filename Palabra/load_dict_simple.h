#pragma once
#ifndef LOAD_DICT_SIMPLE_H
#define LOAD_DICT_SIMPLE_H
#include "load_dict_strategy.h"
//加载词典文件，用于加载测试格式
class LoadDictSimple :
	public LoadDictStrategy
{
public:
	LoadDictSimple();
	virtual ~LoadDictSimple();
	virtual const Dict Load(const std::string &path) override;
};


#endif  // !LOAD_DICT_SIMPLE_H