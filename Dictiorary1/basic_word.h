#pragma once
#ifndef BASIC_WORD_H
#define BASIC_WORD_H
#include<string>
#include<vector>
#include<iostream>
#include"meaning.h"
//���������ࣨ�洢�ֵ��е���Ϣ)��
//��Ϊ��Աword==""����ʾδ�ҵ����ʡ�
struct BasicWord
{
	//Ӣ�ĵ���
	std::string word;
	//����
	std::string phonetic;
	std::vector<Meaning> meaning;
	int importance;//��������ʱ����
	//�ֵ��ǩ������CET-4
	std::vector<std::string> tag;
	//���������
	friend std::ostream &operator<<(std::ostream &o, const BasicWord &basic_word);
	//���ݵ�����ĸ������
	friend bool operator<(const BasicWord& a, const BasicWord& b);
	inline operator std::string() { return word; }
	inline bool empty() const { return word.empty(); }
};


//**************************
//the definition of inline functions
//**************************
inline bool operator<(const BasicWord &a, const BasicWord &b)
{
	return a.word < b.word;
}
#endif // !BASIC_WORD_H