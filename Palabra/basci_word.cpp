#include "basci_word.h"

void operator<<(std::ostream & o, const BasicWord & word)
{
	o << word.word << "\t[" << word.phonetic << "]" << std::endl;
	for (auto &i : word.meaning)
	{
		o << "  " << i.part_of_speech << "."
			<< i.chinese_meaning << std::endl;
		o << "    " << i.sentence << std::endl;
	}
	o << "  tags:";
	for (auto i = word.tag.begin(); i != word.tag.end(); ++i)
		o << *i << (((i + 1) != word.tag.end()) ? "," : "");
	//o << std::endl;
}

