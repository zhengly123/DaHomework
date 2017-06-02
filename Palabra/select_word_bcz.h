#pragma once
#include<queue>
#include<set>
#include"select_word_interface.h"
#include"user_dict.h"
#include"user_info.h"
//priority_queue�Ƚ���
class Compare
{
public:
	inline bool operator()(const UserWord &lhs, const UserWord &rhs)
	{
		if (lhs.importance >= 0 && rhs.importance == -1) return true;
		else if ((lhs.importance == rhs.importance
			|| (lhs.importance >= 0 && rhs.importance >= 0)))
			if (lhs.last_time < rhs.last_time) return true;
		return false;
	}
};

//���հٴ�ն(bcz)��ģʽѡȡ����
class SelectWordBcz :
	public SelectWordInterface
{
public:
	using SelectWordInterface::SelectWordInterface;
	virtual ~SelectWordBcz();
	// ѡ��ģʽ
	virtual UserWord Select() override;
	virtual void Update(const UserWord word) override;//word��tag�ȸ���Ӧ�����ⲿ���������

private:
	std::priority_queue<UserWord, std::vector<UserWord>, Compare> heap;
	//UserWord last_word_;
};