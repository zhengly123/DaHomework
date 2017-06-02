#pragma once
#ifndef LOAD_USERDATA_SIMPLE_H
#define LOAD_USERDATA_SIMPLE_H
#include<fstream>
#include"load_user_dict_strategy.h"
//加载用户词典文件，用于加载simple格式（测试时使用的最简单格式）
//输入顺序为:
//word
//tag
//note
//review_num error_num last_time importance（-1表示不再出现）
//class LoadUserDictSimple :LoadUserDictStrategy
//{
//public:
//	LoadUserDictSimple();
//	virtual ~LoadUserDictSimple();
//	//virtual UserDict Load(const std::string &path) override;
//	//修改基类接口，本函数弃用
//	//virtual bool Load(const std::string &path, UserDict & dict) override;
//	//virtual bool Save(const std::string path, const UserDict& user_dict) override;
//};

#endif  // !LOAD_USERDATA_SIMPLE_H
