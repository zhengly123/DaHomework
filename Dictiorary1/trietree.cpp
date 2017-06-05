#include "trietree.h"
#include <QDebug>
void opt(Trie* root, vector<string> allwords)
{
    for(auto iter = allwords.begin();iter!=allwords.end();iter++)
    {
        (*iter).c_str();
        insert(root,(*iter).c_str());
        qDebug()<<QString::fromStdString(*iter);
    }
    return;
}
void insert(Trie *root,const char *s)     //将单词s插入到字典树中
{
    if(root==NULL||*s=='\0')
        return;
    int i;
    Trie *p=root;
    while(*s!='\0')
    {

        if(int(*s-'a')<-7&&int(*s-'a')>=-32)
        {
            if(p->next[int(*s-'a'+32)]==NULL)        //如果不存在，则建立结点
            {
                Trie *temp=(Trie *)malloc(sizeof(Trie));
                for(i=0;i<MAX;i++)
                {
                    temp->next[i]=NULL;
                }
                temp->isStr=false;
                p->next[int(*s-'a'+32)]=temp;
                p=p->next[int(*s-'a'+32)];
            }
            else
            {
                p=p->next[*s-'a'+32];
            }

        }
        else if(int(*s-'a')>=0&&int(*s-'a')<=25)
        if(p->next[*s-'a']==NULL)        //如果不存在，则建立结点
        {
            Trie *temp=(Trie *)malloc(sizeof(Trie));
            for(i=0;i<MAX;i++)
            {
                temp->next[i]=NULL;
            }
            temp->isStr=false;
            p->next[*s-'a']=temp;
            p=p->next[*s-'a'];
        }
        else
        {
            p=p->next[*s-'a'];
        }
        else break;
        s++;
    }
    p->isStr=true;                       //单词结束的地方标记此处可以构成一个单词
}










//s1.c_str();

/*auto iter=ivector.begin();iter!=ivector.end();iter++
 *
 *
 *
 * typedef struct TrieNode                     //Trie结点声明
{
    bool isStr;                            //标记该结点处是否构成单词
    struct TrieNode *next[MAX];            //儿子分支
}Trie;
void opt(Trie*,vector<string>);
void insert(Trie*,string);

#endif // TRIETREE_H
*/
