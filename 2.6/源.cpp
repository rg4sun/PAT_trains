#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

// 问题 A: 习题7-5 字符串逆序存放
void str_reverse(string &a) {// 要引用，不然不会改变传入的string
	for (int i=0; i < a.length() / 2; i++) {
		char tmp = a[i];
		a[i] = a[a.length() - 1 - i];
		a[a.length() - 1 - i] = tmp;
	}
}
void ex_a() {
	string a;
	cin >> a;
	str_reverse(a);
	cout << a;
}


int main()
{
	ex_a();

	return 0;
}