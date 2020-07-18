#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

inline void drawSquare(int n, char a) {
	for (int i = 0; i < (int)round((double)n / 2); i++) {
		if (i == 0 || i == (int)round((double)n / 2) - 1) {
			for (int j = 0; j < n; j++) {
				printf("%c", a);
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (j == 0 || j == n - 1) {
					printf("%c", a);
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

inline void test() {
	int n;
	char a;
	scanf("%d %c", &n, &a);
	drawSquare(n, a);
}