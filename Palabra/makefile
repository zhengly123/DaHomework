# Project: Project1
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = main.o basic_word.o jsoncpp.o load_basic_dict_json.o load_basic_dict_strategy.o load_user_dict_json.o load_user_dict_strategy.o logger.o logger_json.o select_word_bcz.o select_word_interface.o user.o user_dict.o user_info.o user_word.o
LINKOBJ  = main.o basic_word.o jsoncpp.o load_basic_dict_json.o load_basic_dict_strategy.o load_user_dict_json.o load_user_dict_strategy.o logger.o logger_json.o select_word_bcz.o select_word_interface.o user.o user_dict.o user_info.o user_word.o
LIBS     = -L"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/lib" -L"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc
INCS     = -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/include" -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/include" -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"C:/Program Files(noninstall)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = Palabra.exe
CXXFLAGS = $(CXXINCS) -std=c++11
CFLAGS   = $(INCS) -std=c++11
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

basic_word.o: basic_word.cpp
	$(CPP) -c basic_word.cpp -o basic_word.o $(CXXFLAGS)

jsoncpp.o: jsoncpp.cpp
	$(CPP) -c jsoncpp.cpp -o jsoncpp.o $(CXXFLAGS)

load_basic_dict_json.o: load_basic_dict_json.cpp
	$(CPP) -c load_basic_dict_json.cpp -o load_basic_dict_json.o $(CXXFLAGS)

load_basic_dict_strategy.o: load_basic_dict_strategy.cpp
	$(CPP) -c load_basic_dict_strategy.cpp -o load_basic_dict_strategy.o $(CXXFLAGS)

load_user_dict_json.o: load_user_dict_json.cpp
	$(CPP) -c load_user_dict_json.cpp -o load_user_dict_json.o $(CXXFLAGS)

load_user_dict_strategy.o: load_user_dict_strategy.cpp
	$(CPP) -c load_user_dict_strategy.cpp -o load_user_dict_strategy.o $(CXXFLAGS)

logger.o: logger.cpp
	$(CPP) -c logger.cpp -o logger.o $(CXXFLAGS)

logger_json.o: logger_json.cpp
	$(CPP) -c logger_json.cpp -o logger_json.o $(CXXFLAGS)

select_word_bcz.o: select_word_bcz.cpp
	$(CPP) -c select_word_bcz.cpp -o select_word_bcz.o $(CXXFLAGS)

select_word_interface.o: select_word_interface.cpp
	$(CPP) -c select_word_interface.cpp -o select_word_interface.o $(CXXFLAGS)

user.o: user.cpp
	$(CPP) -c user.cpp -o user.o $(CXXFLAGS)

user_dict.o: user_dict.cpp
	$(CPP) -c user_dict.cpp -o user_dict.o $(CXXFLAGS)

user_info.o: user_info.cpp
	$(CPP) -c user_info.cpp -o user_info.o $(CXXFLAGS)

user_word.o: user_word.cpp
	$(CPP) -c user_word.cpp -o user_word.o $(CXXFLAGS)
