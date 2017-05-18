#pragma once
#ifndef LOAD_BASIC_DICT_SIMPLE_H
#define LOAD_BASIC_DICT_SIMPLE_H
#include "load_basic_dict_strategy.h"
//加载词典文件，用于加载测试格式
class LoadBasicDictSimple :
	public LoadBasicDictStrategy
{
public:
	LoadBasicDictSimple();
	virtual ~LoadBasicDictSimple();
	virtual const BasicDict Load(const std::string &path) override;
};


#endif  // !LOAD_BASIC_DICT_SIMPLE_H