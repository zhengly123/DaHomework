#pragma once
#include<queue>
#include<set>
#include "select_word_interface.h"
#include"user_dict.h"
//priority_queue�Ƚ���
class Compare
{
public:
	inline bool operator()(const UserWord &lhs, const UserWord &rhs)
	{
		if (lhs.importance >= 0 && rhs.importance == -1) return true;
		else if ((lhs.importance == rhs.importance
			|| (lhs.importance >= 0 && rhs.importance >= 0)))
			if (lhs.last_appear_time < rhs.last_appear_time) return true;
		return false;
	}
};

//���հٴ�ն(bcz)��ģʽ
class SelectWordBcz :
	public SelectWordInterface
{
public:
	SelectWordBcz(const ListType &list, UserDict &dict);
	virtual ~SelectWordBcz();
	// ѡ��ģʽ
	void SetMode(int mode);
	virtual UserWord Select() override;
	void Update(const UserWord &word);//word��tag�ȸ���Ӧ�����ⲿ���������
private:
	std::priority_queue<UserWord, std::vector<UserWord>, Compare> heap;
	//0Ϊ��ϣ�1Ϊ��ѧϰ��2Ϊ��ϰ
	int mode_;
	//UserWord last_word_;
	ListType::const_iterator next_word_;
};