#include "load_user_dict_json.h"
#include "json/json.h"
using namespace Json;
const std::string InitString= R"({"dict":[],"history":[],"lev":"senior","num":30})";
LoadUserDictJson::LoadUserDictJson()
{
}

LoadUserDictJson::~LoadUserDictJson()
{
}

bool LoadUserDictJson::Load(const std::string & path, UserDict & dict, UserInfo & info)
{
	std::string word_spelling, PoS, translation, sentence;
	std::ifstream is(path);
	Value root;
	Date date = {};
	UserWord word = {};
	if (is.fail())//如果文件不存在，创建新文件
	{
		ofstream *os = new ofstream(path);
		(*os) << InitString;
		os->close();
		delete os;
		is.close();
		is.open(path);
	}
	is >> root;
	info.level = root[JLevel].asString();
	info.daily_number_of_word = root[JDailyNumberOfWord].asInt();
	for (const auto &record : root[JHistory])
	{
		date.year = record[JYear].asInt();
		date.month = record[JMonth].asInt();
		date.day = record[JDay].asInt();
		info.history.push_back(make_pair(date,
			record[JCount].asInt()));
	}
	for (const auto &i : root[JDictionary])
	{
		word.word = i[JWord].asString();
		word.review_num = i[JReviewNumber].asInt();
		word.error_num = i[JErrorNum].asInt();
		word.last_time = i[JLastTime].asInt();
		word.importance = i[JImportance].asInt();
		word.note = i[JNote].asString();
		word.favor = i[JFavor].asBool();
		dict.insert(word);
	}
	return true;
}

bool LoadUserDictJson::Save(const std::string path, const UserDict & user_dict, const UserInfo & info)
{
	Value root, record, word;
	Json::FastWriter fast_writer;
	ofstream os(path);
	root[JLevel] = info.level;
	root[JDailyNumberOfWord] = info.daily_number_of_word;
	for (const auto &i : info.history)
	{
		record[JYear] = i.first.year;
		record[JMonth]=i.first.month;
		record[JDay] = i.first.day;
		record[JCount] = i.second;
		root[JHistory].append(record);
	}
	for (auto i =user_dict.cbegin();i!=user_dict.cend();++i)
	{
		word[JWord] = i->word;
		word[JReviewNumber] = i->review_num;
		word[JErrorNum] = i->error_num;
		word[JLastTime] = i->last_time;
		word[JImportance] = i->importance;
		word[JNote] = i->note;
		word[JFavor] = i->favor;
		root[JDictionary].append(word);
	}
	os << fast_writer.write(root);
	return true;
}