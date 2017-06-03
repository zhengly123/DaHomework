#pragma once
#ifndef USER_WORD_H
#define USER_WORD_H
#include<string>
#include<vector>
#include"sentence.h"
//�û��ĵ����ࣨ�洢�û����ڵ��ʵ���Ϣ��
//����˳��Ϊ:
//word
//tag
//note
//review_num error_num last_appear_time importance
struct UserWord
{
	std::string word;
	std::vector<std::string> note;
	std::vector<std::string> tag;
	int review_num;
	int error_num;
	int last_appear_time;
	int importance;//[1,5]
	friend bool operator<(const UserWord& a, const UserWord& b);
	//���������
	friend void operator<<(std::ostream &o, const UserWord &user_word);
	//���ݵ�����ĸ������
	friend bool operator<(const UserWord& a, const UserWord& b);
};
#endif  // !USER_WORD_H