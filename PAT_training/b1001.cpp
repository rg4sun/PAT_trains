#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>

inline int callatz(int n) {
	int step = 0;
	if (n == 1) {
		return step;
	}
	while (n != 1) {
		if (n % 2 == 0) {// 偶数
			n /= 2;
		}
		else {
			n = (3 * n + 1) / 2;
		}
		step += 1;
	}
	return step;
}

inline void test() {
	int n;
	scanf("%d", &n);
	printf("%d", callatz(n));
}