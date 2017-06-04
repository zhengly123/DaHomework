#include "load_basic_dict_json.h"
#include "json/json.h"
#include<exception>
#include<stdexcept>
using namespace Json;
LoadBasicDictJson::LoadBasicDictJson()
{
}

LoadBasicDictJson::~LoadBasicDictJson()
{
}

bool LoadBasicDictJson::Load(const std::string & path, BasicDict & dict)
{
	std::string word_spelling, PoS, translation, sentence;
	std::ifstream is(path);
	if (is.fail())
		throw RuntimeError("Input failure");
	Value root;
	is >> root;
	for (const auto &i : root)
	{
		BasicWord word;
		word.word = i["word"].asString();
		word.phonetic = i["pho"].asString();
		//word.importance = -1;
		for (auto j = i["tag"].begin(); j != i["tag"].end(); ++j)
			word.tag.push_back(j->asString());
		for (const auto &j : i["mean"])
		{
			Meaning meaning;
			meaning.part_of_speech = j["PoS"].asString();
			meaning.chinese_meaning = j["exp"].asString();
			word.meaning.push_back(meaning);
		}
		dict.insert(word);
	}
	return true;
}
