#include "select_word_bcz.h"
#include<ctime>
#include<exception>
SelectWordBcz::SelectWordBcz(const ListType & list, UserDict & dict)
	: SelectWordInterface(list, dict), mode_(0)
{
	next_word_ = list_.cbegin();
}

SelectWordBcz::~SelectWordBcz()
{
	while (!heap.empty())
	{
		auto temp = heap.top();
		heap.pop();
		dict_.insert(temp);
	}
}


// ѡ��ģʽ
void SelectWordBcz::SetMode(int mode)
{
	mode_ = mode;
}

UserWord SelectWordBcz::Select()
{
	UserWord word = {};
	bool old_word;//�Ƿ�ѡ��ϰ

	if (mode_ == 2) old_word = true;
	else if (mode_ == 1) old_word = false;
	else
	{
		if (heap.empty())
			old_word = false;
		else if (next_word_ == list_.cend())
			old_word = true;
		else old_word = rand() & 1;
	}

	if (old_word)
	{//ѡ���ϴ�
		if (!heap.empty())
		{
			word = heap.top();
			heap.pop();
		}
		else throw std::out_of_range("No more old word.");
	}
	else
	{//ѡ���´�
		if (next_word_ != list_.cend())
		{
			word.word = *next_word_;
			++next_word_;
		}
		else throw std::out_of_range("No more new word.");
	}
	return word;
}

void SelectWordBcz::Update(const UserWord &word)
{
	/*if (last_word_.word == "")
	{
		throw std::logic_error("No word could be updated");
	}
	last_word_.review_num++;
	last_word_.last_time = time(0);	
	if (!accurate) last_word_.error_num++;
	if (last_word_.review_num >= 3
		&& (double(last_word_.error_num) / last_word_.review_num < 0.65))
		last_word_.importance = -1;*/
	heap.push(word);
	//dict_.insert(last_word_);//����ʱ����
	//memset(&last_word_, 0, sizeof(last_word_));
}

//inline void SelectWordBcz::SetLastWord(std::string word)
//{
//	memset(&last_word_, 0, sizeof(last_word_));
//	last_word_.word = word;
//	last_word_.last_time = time();
//	last_word_.review_num = 1;
//	last_word_.
//}
