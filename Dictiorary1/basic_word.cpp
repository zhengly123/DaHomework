#include "basic_word.h"

std::ostream & operator<<(std::ostream & os, const BasicWord & word)
{
	os << word.word << "\t[" << word.phonetic << "]" << std::endl;
	for (auto &i : word.meaning)
	{
		os << "  " << i.part_of_speech << "."
			<< i.chinese_meaning << std::endl;
		os << "    " << i.sentence << std::endl;
	}
	os << "  tags:";
	for (auto i = word.tag.begin(); i != word.tag.end(); ++i)
		os << *i << (((i + 1) != word.tag.end()) ? "," : "");
	//os << std::endl;//由外部程序决定
	return os;
}

