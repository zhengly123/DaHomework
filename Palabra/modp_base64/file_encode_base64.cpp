//  Base64系列第四篇 C/C++中使用Base64编码解码(从chromium库中抽取)
//  by MoreWindows( http://blog.csdn.net/MoreWindows )   
 
#include "base64.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <stdexcept>
using namespace std;
int ConvertFileToBase64(const string Path, string &base64_str)
{
	string input_str, output_str;
	FILE *fp = fopen("text.wav", "rb");//TODO:change the file name
	if (fp)
	{
		fseek(fp, 0, SEEK_END);
		int len = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		input_str.resize(len);
		fread((void*)input_str.data(), 1, len, fp);
		fclose(fp);
	}
	else
	{
		throw runtime_error("Cannot open file!");
	}
	////////////////////////////
	//  cout<<"origin text: \n"<<input_str<<endl;
	Base64Encode(input_str, &base64_str);
	//std::cout << base64_str;
	//  cout<<"encode: \n"<<base64_str<<endl;
	//Base64Decode(base64_str, &output_str);//TODO:Debug code
	//std::ofstream fout("a.wav", ios::binary);
	//fout.write(output_str.c_str(), sizeof(char) * (output_str.size()));
	//fout.close();

	//  cout<<"decode: \n"<<output_str<<endl;
	return 0;
}