#pragma once
#include"basci_word.h"
#include"set"
#include"dict_template.h"
using BasicDict = DictTemplate<BasicWord>;
//�ʵ��࣬�������е��ʺͽ���
//class BasicDict
//{
//private:
//	//�����޸�
//	const std::set<BasicWord> dict_;
//public:
//	//�����ʼ��
//	BasicDict(std::set<BasicWord> & dict);
//	BasicDict(std::set<BasicWord> && dict) noexcept;
//	~BasicDict();
//	//inline void insert(const BasicWord &word);//dict���ܲ��룬ֻ�ܳ�ʼ��
//	
//	inline const std::set<BasicWord>::const_iterator cbegin() const;
//	inline const std::set<BasicWord>::const_iterator cend() const;
//	//���ҵ���
//	BasicWord Search(const std::string& word) const;
//	//���������б�
//	const std::vector<std::string> WordList() const;
//};

//**************************
//the definition of inline functions
//**************************
//inline const std::set<BasicWord>::const_iterator BasicDict::cbegin() const
//
//inline const std::set<BasicWord>::const_iterator BasicDict::cend() const
//{
//	return dict_.cend();
//}
