#include<cstdio>
#include<cmath>
#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用

// 问题 A: 例题4-1 一元二次方程求根 【和2.2-E题略有不同】
void ex_a() {
	double a, b, c;
	a = b = c = 0;
	while (1) {
		if (a == 0) {
				scanf("%lf %lf %lf", &a, &b, &c);
			}
		else
		{
			break;
		}
	}
	if ((b * b - 4 * a * c) <= 0) {
		printf("%s\n", "No real roots!");
	}
	else {
		printf("r1=%7.2f\nr2=%7.2f", (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a), (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));
	}
	
}

//问题 B : 例题4 - 2 比较交换实数值
void ex_b() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	if (a > b) {
		printf("%.2f %.2f\n", b, a);
	}
	else {
		printf("%.2f %.2f\n", a, b);
	}
}

//问题 C : 例题4 - 3 比较交换3个实数值，并按序输出
void small_swap(double& x, double& y) {
	if (x > y) {
		double tmp = x;
		x = y;
		y = tmp;
	}
}

void ex_c() {
	double a, b, c, tmp;
	scanf("%lf %lf %lf", &a, &b, &c);
	// 思路，始终保持tmp记录两数中较小的
	// 使得 a < b, a < c
	small_swap(a, b);
	small_swap(a, c);
	// 使得 b < c
	small_swap(b, c);
	printf("%.2f %.2f %.2f\n", a, b, c);
}

// 问题 D: 习题4-4 三个整数求最大值
// 用上题我的small_swap就好了, 改参数类型
void small_swap_int(int& x, int& y) {
	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
}

void ex_d() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	small_swap_int(a, b);
	small_swap_int(a, c);
	small_swap_int(b, c);
	printf("%d\n", c);

}

//问题 E: 习题4-10-1 奖金计算
void ex_e()
{
	double i;
	scanf("%lf", &i);
	if (i <= 100000) {
		printf("%.2f\n", 0.1 * i);
	}
	else if (i <= 200000) {
		printf("%.2f\n", 0.075 * (i- 100000) + 0.1* 100000);
	}
	else if (i <= 400000) {
		printf("%.2f\n", 0.05*(i- 200000) + 0.075 * 200000 + 0.1 * 100000);
	}
	else if (i <= 600000) {
		printf("%.2f\n", 0.03*(i - 400000) - 0.05 * 400000 + 0.075 * 200000 + 0.1 * 100000);
	}
	else if (i <= 1000000) {
		printf("%.2f\n", 0.015*(i - 600000) - 0.03 * 600000 - 0.05 * 400000 + 0.075 * 200000 + 0.1 * 100000);
	}
	else {
		printf("%.2f\n", 0.01* (i - 1000000) - 0.015 * 1000000 - 0.03 * 600000 - 0.05 * 400000 + 0.075 * 200000 + 0.1 * 100000);
	}
}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	ex_e();

	return 0;
}