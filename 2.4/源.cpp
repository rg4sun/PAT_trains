#include<cstdio>
#include<cmath>
#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用

// 问题 A: 例题5-1-1 连续自然数求和
void ex_a() {
	int sum = 0, i =0;
	while (i < 101) {
		sum += i;
		i++;
	}
	printf("%d\n", sum);
}

// 问题 B: 例题5-1-2 连续自然数求和- do-while
void ex_b() {
	int sum = 0, i = 0;
	do {
		sum += i;
		i++;
	} while (i < 101);
	printf("%d\n", sum);
}

// 问题 C: 例题5-1-3 连续自然数求和 -for
void ex_c() {
	int sum = 0;
	for (int i = 1; i < 101; i++) {
		sum += i;
	}
	printf("%d\n", sum);
}

// 问题 D: 例题5-1-4 连续自然数求和 - break
void ex_d() {
	int sum, i, n;
	sum = i = 0;
	scanf("%d", &n);
	while (1) {
		i++;
		if (i > n) {
			break;
		}
		sum += i;
	}
	printf("%d\n", sum);
}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	ex_d();

	return 0;
}