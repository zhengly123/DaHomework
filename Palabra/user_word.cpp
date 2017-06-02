#include "user_word.h"
#include<iostream>
using namespace std;

bool operator<(const UserWord & a, const UserWord & b)
{
	return a.word < b.word;
}

std::ostream &operator<<(std::ostream & os, const UserWord & user_word)
{
	if (!user_word.note.empty())
		os << "  note:" << user_word.note[0] << "\n";
	//if (!user_word.sentence.empty())
	//	os << "  User sentence:" << user_word.sentence[0].english << "\n";
	//if (!user_word.tag.empty())
	//{
	//	os << "  tag:";
	//	for (const auto &i : user_word.tag)
	//		os << i << "  ";
	//	os << "\n";
	//}
	return os;
}
