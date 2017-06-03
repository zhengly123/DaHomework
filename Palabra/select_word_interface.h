#pragma once
#ifndef SELECT_WORD_INTERFACE_H
#define SELECT_WORD_INTERFACE_H
#include<string>
#include<vector>
#include"user_dict.h"
#include"basic_dict.h"
using ListType = std::vector<std::string>;
//ѡȡ���ʵĳ�����
class SelectWordInterface
{
public:
	//mode 0Ϊ��ϣ�1Ϊ��ѧϰ��2Ϊ��ϰ
	//Warning:�ʵ��಻Ҫʹ����ֵ
	SelectWordInterface(const ListType new_word_list,
		const ListType old_word_list, const BasicDict &basic_dict
		, UserDict &user_dict, const int mode = 0);
	virtual ~SelectWordInterface();
	// ������һ������
	virtual UserWord Select() = 0;
	virtual void Update(UserWord word) = 0;
	virtual int NumberOfRestNewWord() = 0;
	virtual int NumberOfRestOldWord() = 0;
	virtual bool Empty() = 0;
protected:
	const ListType new_word_list_, old_word_list_;//��Ӧʹ��&����ΪToWordList����ֵ
	const BasicDict *const basic_dict_;
	UserDict *user_dict_;
	bool updated;//UserData�Ƿ����
	ListType::const_iterator next_word_;
	int mode_;//0Ϊ��ϣ�1Ϊ��ѧϰ��2Ϊ��ϰ
};
//�õ��������ʲ�ͬ��word�ĵ��ʣ����ڲ���
std::vector<std::string> GetThreeWord(const ListType &list, const std::string word);
ListType GetOldWordList(const UserDict &dict);
ListType GetNewWordList(const ListType new_list, const UserDict &dict, int num);
#endif  // !SELECT_WORD_INTERFACE_H

