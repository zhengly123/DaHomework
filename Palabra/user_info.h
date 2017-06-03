#pragma once
#ifndef USER_INFO_H
#define USER_INFO_H
#include<string>
#include<vector>
#include<ctime>
using namespace std;

struct Date
{
	int day; //Ŀǰ�·ݵ�����, ��Χ01-31
	int month; //����Ŀǰ�·�, ��һ������, ��Χ��0-11
	int year; //��1900 ���������������
};

struct UserInfo
{
	string level;
	vector<pair<Date, int>> history;
};

#endif  // !USER_INFO_H