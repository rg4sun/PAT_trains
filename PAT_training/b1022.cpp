#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

// 直接char强制转换，并不能完成数字变成字符数字
// 如 （char 97）=> ‘a’
//inline string baseConverter(int x, int base) { 
//	string result = "";
//	while (x) {
//		result = (char)(x % base) + result;
//		x /= base;
//	}
//	return result;
//}

inline string baseConverter(int x, int base) {
	string result = "";
	while (x) {
		char tmp[2];
		sprintf(tmp, "%d", x % base);
		result = tmp + result;
		x /= base;
	}
	return result;
}

inline void test() {
	cout << baseConverter(123+456, 8);
}

