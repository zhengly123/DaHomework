#pragma once
#ifndef MEANING_H
#define MEANING_H
#include<string>
#include"sentence.h"
//���ʵ�һ������
struct Meaning
{
	//���ԣ���Ҫ��׼���洢
	std::string part_of_speech;
	std::string chinese_meaning;
	//ֻ����һ������
	std::string sentence;//whether to use vector or not
};

#endif  // !MEANING_H