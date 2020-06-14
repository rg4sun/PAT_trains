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

// 问题 D: A+B 输入输出练习IV
void ex_d() {
	int N;
	while (scanf("%d", &N), N != 0) {
		int* a = (int*)malloc(N * sizeof(int));
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			tmp += a[i];
		}
		printf("%d\n", tmp);
	}
}

// 问题 E: A+B 输入输出练习V
void ex_e() { // 输出超限0
	int N;
	scanf("%d", &N);
	while (N--){
		int M;
		scanf("%d", &M);
		int* a = (int*)malloc(M * sizeof(int));
		int tmp = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d", &a[i]);
			tmp += a[i];
		}
		printf("%d\n", tmp);
	}
}

// 问题 F: A+B 输入输出练习VI
void ex_f() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int* a = (int*)malloc(N * sizeof(int));
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			tmp += a[i];
		}
		printf("%d\n", tmp);
	}
}


int main() {

	ex_e();

	return 0;
}