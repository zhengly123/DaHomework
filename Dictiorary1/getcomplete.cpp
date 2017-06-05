#include "getcomplete.h"
#include <queue>
#include <QDebug>
QStringList GetComplete(QString input,Trie* root)
{
    char* s = (char *)malloc((input.toStdString().length()+1)*sizeof(char));//(input.toStdString()).c_str();//data = (char *)malloc((len+1)*sizeof(char));

    input.toStdString().copy(s,input.toStdString().length(),0);//s1.copy(data,len,0);

    QStringList a;
    if(input=="")
        return a;
   // a<<input;
    Trie *p=root;
    //string coor = "";

    if(p==NULL)
        return a;
    //qDebug()<<000003003030;
    /*while(int(*s-'A')<0||(int(*s-'A')>25&&int(*s-'a')<0)||int(*s-'a')>25)
    {
        s++;
    }*/
       while(p!=NULL)
       {
           if(int(*s-'A')>=0&&int(*s-'A')<=25)
           {
                p = p->next[*s-'A'];
           }
           else if(int(*s-'a')>=0&&int(*s-'a')<=25)
           {

               p = p->next[*s-'a'];
           }
           else break;
           //coor+=*s;
           s++;
       }
       queue<Trie*> q;
       queue<string> stringq;
       q.push(p);
       stringq.push(input.toStdString());
       int sum=0;
       //bool End = 1;
       Trie* temp=NULL;
       string tempstring = "";
      // qDebug()<<(p==NULL);
       while(sum<=9&&(!q.empty())&&p!=NULL)
       {

           temp = q.front();
           tempstring = stringq.front();
               q.pop();
               stringq.pop();
              // qDebug()<<QString::fromStdString(tempstring);
           if(temp->isStr==true)
           {
               ++sum;
               a<<QString::fromStdString(tempstring);
           }
           for(int j=0;j<MAX;j++)
           {
               if(temp->next[j]!=NULL)
               {
                   qDebug()<<char('a'+j);
                  q.push(temp->next[j]);
                  stringq.push(tempstring+char('a'+j));
               }
           }
       }
       return a;
}

