#include "load_basic_dict_simple.h"

LoadBasicDictSimple::LoadBasicDictSimple()
{
}


LoadBasicDictSimple::~LoadBasicDictSimple()
{
}

const BasicDict LoadBasicDictSimple::Load(const std::string & path)
{
	std::string word_spelling, PoS, translation, sentence;
	std::ifstream is(path);
	std::set<BasicWord> dict;
	Meaning meaning;
	while (is)
	{
		BasicWord word = {};
		getline(is, word.word);
		getline(is, meaning.part_of_speech);
		getline(is, meaning.chinese_meaning);
		getline(is, meaning.sentence);
		word.meaning.clear();
		word.meaning.push_back(meaning);
		dict.insert(word);
	}
	return BasicDict(std::move(dict));
}
