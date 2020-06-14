#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

// 本小节是规范OJ输入输出的练习
// 黑盒测试：单点测试、多点测试
// codeup采取多点测试，PAT采取单点测试

// 问题 A: A+B 输入输出练习I
void ex_a() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}
}

// 问题 B: A+B 输入输出练习II
void ex_b() {
	int N,a,b;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}

// 问题 C: A+B 输入输出练习III
void ex_c() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		printf("%d\n", a + b);
	}
}

int main() {

	return 0;
}