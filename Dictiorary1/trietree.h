#ifndef TRIETREE_H
#define TRIETREE_H
#include <iostream>
#include<cstdlib>
#include <cstdio>
#include <vector>
#define MAX 26
using namespace std;
typedef struct TrieNode                     //Trie结点声明
{
    bool isStr;                            //标记该结点处是否构成单词
    struct TrieNode *next[MAX];            //儿子分支
}Trie;
void opt(Trie*,vector<string>);
void insert(Trie*,const char *);

#endif // TRIETREE_H
