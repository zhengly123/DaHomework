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
	int month; //代表目前月份, 从一月算起, 范围从0-11
	int year; //从1900 年算起至今的年数
};

struct UserInfo
{
	string level;
	vector<pair<Date, int>> history;
};

#endif  // !USER_INFO_H