#ifndef GETCOMPLETE_H
#define GETCOMPLETE_H
#include <QStringList>
#include <QTextStream>
#include"user_dict.h"
#include"user_word.h"
#include"select_word_bcz.h"
#include"load_basic_dict_json.h"
#include"load_user_dict_json.h"
#include"logger_json.h"
#include "json/json.h"
#include "trietree.h"
QStringList GetComplete(QString,Trie*);
#endif // GETCOMPLETE_H
