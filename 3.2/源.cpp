#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>

//问题 B: 找x

int findX(int n) {
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int x;
	scanf("%d", &x);
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

void ex_b_err() { // 这个只能测一组数据
	int n;
	scanf("%d", &n);
	printf("%d", findX(n));
}

void ex_b_() { 
	int n;
	while (scanf("%d", &n) != EOF) { // 多组数据时候，一定要加上这个循环
		printf("%d\n", findX(n)); // 输出要加 \n 才正确通过
	}
}

int main()
{
	ex_b();
	return 0;
}