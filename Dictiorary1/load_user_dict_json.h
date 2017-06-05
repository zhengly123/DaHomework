#pragma once
#ifndef LOAD_USER_DICT_JSON_H
#define LOAD_USER_DICT_JSON_H
#include<fstream>
#include"load_user_dict_strategy.h"
const std::string JLevel = "lev";
const std::string JDailyNumberOfWord = "num";
const std::string JHistory = "history";
	const std::string JYear = "year";
	const std::string JMonth = "mon";
	const std::string JDay = "day";
	const std::string JCount = "cou";
const std::string JDictionary = "dict";
	const std::string JWord = "Word";
	const std::string JReviewNumber = "rev";
	const std::string JErrorNum = "err";
	const std::string JLastTime = "last";
	const std::string JImportance = "imp";
	const std::string JNote = "note";
	const std::string JFavor = "fav";

//加载用户词典文件，用于加载simple格式（测试时使用的最简单格式）
//输入顺序为:
//word
//tag
//note
//review_num error_num last_time importance（-1表示不再出现）
class LoadUserDictJson :LoadUserDictStrategy
{
public:
	LoadUserDictJson();
	virtual ~LoadUserDictJson();
	//virtual UserDict Load(const std::string &path) override;
	//修改基类接口，本函数弃用
	virtual bool Load(const std::string &path, UserDict & dict, UserInfo &info);
	virtual bool Save(const std::string path, const UserDict& user_dict,
		const UserInfo &info);
};

#endif  // !LOAD_USER_DICT_JSON_H