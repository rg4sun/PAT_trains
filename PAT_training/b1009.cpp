#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

inline string strReverse(string str) {
	string reStr = "";
	int subStrStart = 0; // 记录每个单词的首字母下标
	//string类的length()或者size()函数返回的是unsigned integer(无符号数)类型。
	//而用在for循环时，正常不会出错，但作为判断条件时，当s.length()等于0时，s.length()-1 不等于 -1
	// https://blog.csdn.net/lonyw/article/details/75268172
	//for (int i = 0; i < str.length(); i++) {// 这里报错：有符号/无符号不匹配，原因见上
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == ' ') {
			//reStr = str.substr(subStrStart, i - 1) + reStr; // 这样会导致每个单词没有空格
			reStr = str.substr(subStrStart, i) + reStr; // i位置是个空格，但是要记得去掉最后一个空格
			subStrStart = i + 1;
		}
	}// erase 成员函数可以删除 string 对象中的子串, 若只有一个index则删除该index（含）及其后面的所以字符
	return reStr.erase(reStr.length() - 1); // 去除最后一个空格
}

inline void test()
{
	string str = "abcde";
	cout << str.substr(2, str.length() - 1);
}