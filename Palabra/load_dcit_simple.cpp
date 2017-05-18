#include "load_dict_simple.h"

LoadDictSimple::LoadDictSimple()
{
}


LoadDictSimple::~LoadDictSimple()
{
}

const Dict LoadDictSimple::Load(const std::string & path)
{
	std::string word_spelling, PoS, translation, sentence;
	std::ifstream is(path);
	std::set<WordDict> dict;
	WordDict word;
	Meaning meaning;
	while (is)
	{
		getline(is, word.word);
		getline(is, meaning.part_of_speech);
		getline(is, meaning.chinese_meaning);
		getline(is, meaning.sentence);
		word.meaning.clear();
		word.meaning.push_back(meaning);
		dict.insert(word);
	}
	return Dict(std::move(dict));
}
