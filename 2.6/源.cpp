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

// 问题 B: 习题7-7 复制字符串中的元音字母
string vowel_extract(string str) {
	string vowels = "";
	for (int i = 0; i < str.length(); i++) {
		bool p = str[i] == 'a' || str[i] == 'e' 
			|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
			|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' 
			|| str[i] == 'O' || str[i] == 'U';
		if (p) {
			vowels += str[i];
		}
	}
	return vowels;
}

void ex_b() {
	string s;
	cin >> s;
	cout << vowel_extract(s);
}

int main()
{
	//ex_a();
	ex_b();

	return 0;
}