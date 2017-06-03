#include "select_word_bcz.h"
#include<ctime>
#include<exception>

SelectWordBcz::~SelectWordBcz()
{

}


// ѡ��ģʽ


UserWord SelectWordBcz::Select()
{
	if (!updated)
		throw logic_error("UserDict have not been updated!");
	UserWord word;
	if (mode_ == 1 && next_word_ == new_word_list_.cend())
		throw exception("No more new word!");
	if (mode_ == 2 && heap.empty())
		throw exception("No more old word!");
	bool old = 0;
	if (mode_ != 0) old = (mode_ == 2);
	else
	{
		if (next_word_ == new_word_list_.cend()) old = 1;
		else if (heap.empty()) old = 0;
		else old = rand() & 1;
	}
	if (old)
	{
		word = heap.top();
		heap.pop();
	}
	else
	{
		word = user_dict_->Search(*next_word_);
		next_word_++;
	}
	updated = 0;
	return word;
}

/*UserWord SelectWordBcz::Select()
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
}*/

void SelectWordBcz::Update(UserWord word)
{
	if (updated)
		throw logic_error("Have been updated!");

	if (word.importance == 0) word.importance = 1;
	if (word.review_num - word.error_num >= 2) word.importance = -1;//�Զ����벻��ϰ
	if (word.importance == 1)
		heap.push(word);
	user_dict_->insert(word);
	updated = true;
	//dict_.insert(last_word_);//����ʱ����
	//memset(&last_word_, 0, sizeof(last_word_));
}

int SelectWordBcz::NumberOfRestNewWord()
{
	return new_word_list_.cend() - next_word_;
}

int SelectWordBcz::NumberOfRestOldWord()
{
	return heap.size();
}

bool SelectWordBcz::Empty()
{
	return (NumberOfRestNewWord() + NumberOfRestOldWord() == 0);
}

//inline void SelectWordBcz::SetLastWord(std::string word)
//{
//	memset(&last_word_, 0, sizeof(last_word_));
//	last_word_.word = word;
//	last_word_.last_time = time();
//	last_word_.review_num = 1;
//	last_word_.
//}
