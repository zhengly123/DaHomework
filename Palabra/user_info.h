#pragma once
#ifndef USER_INFO_H
#define USER_INFO_H
#include<string>
#include<vector>
#include<ctime>
using namespace std;

struct Date
{
	int day; //目前月份的日数, 范围01-31
	int month; //代表目前月份, 从一月算起, 范围从1-12
	int year; //20xx
};

struct UserInfo
{
	string level;//被单词的难度，例如CET-6
	int daily_number_of_word;//每次背单词的数量
	vector<pair<Date, int>> history;//背单词的历史记录
};

#endif  // !USER_INFO_H