#include "dict.h"


Dict::Dict(std::set<WordDict>& dict):dict_(dict)
{
}

Dict::Dict(std::set<WordDict>&& dict) noexcept : dict_(dict)
{
}

Dict::~Dict()
{
}

WordDict Dict::Search(const std::string & word) const
{
	WordDict worddict;
	worddict.word = word;
	return *dict_.find(worddict);
}

const std::vector<std::string> Dict::WordList() const
{
	std::vector<std::string> wordlist;
	for (auto i : dict_)
		wordlist.push_back(i.word);
	return wordlist;
}
