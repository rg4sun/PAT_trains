#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<iostream>	
#include<string>
using namespace std;

// 问题 I: 【字符串】回文串
bool isPalindrome(string str) {
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i])
			return false;
	}
	return true;
}

void ex_i() {
	string str;
	cin >> str;
	if (isPalindrome(str))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	ex_i();
	return 0;
}