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

//�����û��ʵ��ļ������ڼ���simple��ʽ������ʱʹ�õ���򵥸�ʽ��
//����˳��Ϊ:
//word
//tag
//note
//review_num error_num last_time importance��-1��ʾ���ٳ��֣�
class LoadUserDictJson :LoadUserDictStrategy
{
public:
	LoadUserDictJson();
	virtual ~LoadUserDictJson();
	//virtual UserDict Load(const std::string &path) override;
	//�޸Ļ���ӿڣ�����������
	virtual bool Load(const std::string &path, UserDict & dict, UserInfo &info);
	virtual bool Save(const std::string path, const UserDict& user_dict,
		const UserInfo &info);
};

#endif  // !LOAD_USER_DICT_JSON_H