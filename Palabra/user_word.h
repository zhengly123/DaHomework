#pragma once
#ifndef USER_WORD_H
#define USER_WORD_H
#include<string>
#include<vector>
#include"sentence.h"
//�û������ࣨ�洢���ڵ��ʵ��û����ݣ���
//��Ϊ��Աword==""����ʾδ�ҵ����ʡ�
struct UserWord
{
	std::string word;
	std::string note;
	//std::vector<std::string> tag;
	bool favor;
	int review_num;//��ϰ����
	int error_num;//�������
	int last_time;//���һ�θ�ϰʱ��
	int importance;//��Ҫ��:0δ������1����ϰ��-1�Ѽ�ס

	friend bool operator<(const UserWord& a, const UserWord& b);
	//���������
	friend std::ostream &operator<<(std::ostream &o, const UserWord &user_word);
	//���ݵ�����ĸ������
	friend bool operator<(const UserWord& a, const UserWord& b);
};
#endif  // !USER_WORD_H