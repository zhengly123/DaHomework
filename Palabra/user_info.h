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
	int month; //����Ŀǰ�·�, ��һ������, ��Χ��1-12
	int year; //20xx
};

struct UserInfo
{
	string level;//�����ʵ��Ѷȣ�����CET-6
	int daily_number_of_word;//ÿ�α����ʵ�����
	vector<pair<Date, int>> history;//�����ʵ���ʷ��¼
};

#endif  // !USER_INFO_H