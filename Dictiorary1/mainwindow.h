#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bookdialog.h"
#include "feedbackdialog.h"
#include "logfiledialog.h"
#include "searchdialog.h"
#include "userdialog.h"
#include "pkdialog.h"
#include "welcomedialog.h"
#include "searchbox.h"
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>
#include <QObject>
#include<fstream>
#include"user_dict.h"
#include"user_word.h"
#include"select_word_bcz.h"
#include"load_basic_dict_json.h"
#include"load_user_dict_json.h"
#include"logger_json.h"
#include "trietree.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
     BasicDict dict;
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

        QString target="请输入你要查找的单词";//待搜索的目标单词

        bool mMoveing=false;
        QPoint mMovePosition;

        QLabel *titlelab;//标题框
        QLineEdit *getwordled;//查词框
        QPushButton *searchbtn;//查词按钮
        QPushButton *bookbtn;//单词本
        QPushButton *userbtn;//用户（登录）
        QPushButton *pkbtn;//对战
        QPushButton *logfilebtn;//日志
        QPushButton *feedbackbtn;//反馈（功能暂定）
        QPushButton *backbtn;//回主界面
        QPushButton *minbtn;//最小化
        QPushButton *closebtn;//关闭
        Trie* root;
        SearchDialog *searchdia=new SearchDialog(this);
        UserDialog *userdia=new UserDialog(this);
        BookDialog *bookdia=new BookDialog(this);
        PkDialog *pkdia=new PkDialog(this);
        LogfileDialog *logfiledia=new LogfileDialog(this);
        FeedbackDialog *feedbackdia=new FeedbackDialog(this);
        WelcomeDialog *welcomedia=new WelcomeDialog(this);

    public slots:
        void showSearchDialog();
        void showUserDialog();
        void showBookDialog();
        void showPkDialog();
        void showLogfileDialog();
        void showFeedbackDialog();
        void showWelcomeDialog();

    public:
        void allhide();
        void getword();
        QString getmain(QString);
        void paintEvent(QPaintEvent *);
        void loadImage();
        void style();
        void mousePressEvent(QMouseEvent*);
        void mouseReleaseEvent(QMouseEvent*);
        void mouseMoveEvent(QMouseEvent*);

};

#endif // MAINWINDOW_H
