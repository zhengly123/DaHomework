#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T16:24:10
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dictiorary
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    pkdialog.cpp \
    searchdialog.cpp \
    userdialog.cpp \
    feedbackdialog.cpp \
    bookdialog.cpp \
    logindialog.cpp \
    export.cpp \
    tread.cpp \
    logfiledialog.cpp \
    welcomedialog.cpp\
searchbox.cpp\
 googlesuggest.cpp \
    getcomplete.cpp\
 jsoncpp.cpp \
     load_user_dict_json.cpp \
     logger_json.cpp \
     select_word_bcz.cpp \
     select_word_interface.cpp \
     load_basic_dict_json.cpp \
     user_dict.cpp \
     load_basic_dict_strategy.cpp \
     load_user_dict_strategy.cpp \
     logger.cpp \
     main.cpp \
     user.cpp \
     basic_word.cpp \
     user_info.cpp \
     user_word.cpp \
    trietree.cpp

HEADERS  += mainwindow.h \
    pkdialog.h \
    bookdialog.h \
    searchdialog.h \
    userdialog.h \
    logfiledialog.h \
    feedbackdialog.h \
    logindialog.h \
    export.h \
    huanyu.h \
    tread.h \
    welcomedialog.h\
    searchbox.h\
 googlesuggest.h \
    getcomplete.h\
   basic_dict.h  \
      dict_template.h  \
      load_user_dict_json.h  \
      json/json.h  \
      load_basic_dict_json.h  \
      load_basic_dict_strategy.h  \
      load_user_dict_strategy.h  \
      logger.h  \
      logger_json.h  \
      meaning.h  \
      select_word_bcz.h  \
      select_word_interface.h  \
      sentence.h  \
      user.h  \
      user_dict.h  \
      basic_word.h  \
      user_info.h  \
      user_word.h  \
    trietree.h

RESOURCES += \
    arrowdown.qrc \
    arrowright.qrc \
    arrowdown.qrc \
    QSS.qrc \
    image.qrc

RC_ICONS=a.ico

FORMS +=

DISTFILES +=
