#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct Student
{
	//int id; int存储不了 13位的数字
	string id;
	int location;
	int grade;
};


inline void test() {
	return;
}