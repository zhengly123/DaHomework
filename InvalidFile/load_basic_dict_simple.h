#pragma once
#ifndef LOAD_BASIC_DICT_SIMPLE_H
#define LOAD_BASIC_DICT_SIMPLE_H
#include "load_basic_dict_strategy.h"
//加载基础词典文件，用于加载simple格式（测试时使用的最简单格式）
class LoadBasicDictSimple :
	public LoadBasicDictStrategy
{
public:
	LoadBasicDictSimple();
	virtual ~LoadBasicDictSimple();
	//virtual const BasicDict Load(const std::string &path) override;
	bool Load(const std::string & path, BasicDict &dict) override;
};


#endif  // !LOAD_BASIC_DICT_SIMPLE_H