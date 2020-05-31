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

//问题 E: 实现求1+2+3+...和的程序，要求得到使使和数大于1000的最小正整数
void ex_e() {
	int sum = 0, i =0;
	for (i = 1; sum < 1001; i++) {
		sum += i;
	}
	i -= 1; // 因为当sum<1001判断完后，i++不管判断结果如何都要执行
	printf("%d\n", i);

}

// 问题 F: 例题5-6 矩阵输出
void ex_f() {
	for (int i = 1; i < 5; i++) {
		printf("%3d%3d%3d%3d%3d\n", i, 2 * i, 3 * i, 4 * i, 5 * i);
	}
}

// 问题 G: 例题5-7 求圆周率pi的近似值
void ex_g_err() {
	double pi = 0;
	for (int i = 1; 1 / (double)(2 * i - 1) >= pow(10, -6); i++) {
		if (i % 2 == 0) { // 这里会导致i变调值，再下一次i++ 的时候就不是序号加了
			i = -i;
		}
		pi += 1 / (double)(2 * i - 1);
	}
	printf("%10.8f", 4 * pi);
}
void ex_g() {
	double pi = 0;
	for (int i = 1; 1 / (double)(2 * i - 1) >= pow(10, -6); i++) {
		if (i % 2 == 0) {
			pi -= 1 / (double)(2 * i - 1);
			continue;
		}
		pi += 1 / (double)(2 * i - 1);
	}
	printf("PI=%10.8f\n", 4 * pi);
}

// 问题 H: 例题5-8 Fibonacci数列
void ex_h() {
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n < 50) {
			break;
		}
	}
	if (n < 3) {
		printf("%d\n", 1);
	}
	else {
		int a = 1, f=2;
		for (int i = 0; i < n - 3; i++) {
			int tmp;
			tmp = a;
			a = f;
			f += tmp;
		}
		printf("%d\n", f);
	}
}

// 问题 I: 习题5-10 分数序列求和
// 这题分子分母都是斐波那契数列
double fibo(int n) { // 这里为了便于后面分数求和，返回double值
	if (n < 3) {
		return (double) 1;
	}
	else {
		int a = 1, f = 2;
		for (int i = 0; i < n - 3; i++) {
			int tmp;
			tmp = a;
			a = f;
			f += tmp;
		}
		return (double) f;
	}
}
void ex_i() {
	// 分子从斐波那契数列的第3项开始
	// 分母从第2项开始
	// 则题目求分数序列前20项，则按分母数到斐波那契数列的第21项
	double sum = 0;
	for (int i = 2; i < 22; i++) {
		sum += fibo(i + 1) / fibo(i);
	}
	printf("%.6f\n", sum);
}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	//ex_e();
	//ex_f();
	//ex_g();
	//ex_h();
	ex_i();

	return 0;
}