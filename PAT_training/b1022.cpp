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

/*
inline string baseConverter(int x, int base) {
	string result = "";
	while (x) {
		char tmp[5];
		sprintf(tmp, "%d", x % base);
		result = tmp + result;
		x /= base;
	}
	return result;
}

inline void test() {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	cout << baseConverter(a+b, d);
}
*/
// 以上代码在 PAT 中部分正确，有一组测试点答案错误

inline void test() {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	a += b;
	int r[32] = { 0 };
	int len = 0;
	while (a) {
		r[len++] = a % d;
		a /= d;
	}
	for (int i = len - 1; i >= 0; i--) { // 这里的 len - 1是因为即使while不再执行，但最后一轮还会给len自增一次
		printf("%d", r[i]);
	}
}

// ummmm 还是不对。，。 我比较怀疑是不是 16进制的字母问题
// 先试试书上给的代码 .,. ummm 书上的代码就对了。，。明明没差啊
void test_key() {
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;
	int ans[31], num = 0;
	do {
		ans[num++] = sum % d;
		sum /= d;
	} while (sum != 0);
	for (int i = num - 1; i >= 0; i--) {
		printf("%d", ans[i]);
	}
}

