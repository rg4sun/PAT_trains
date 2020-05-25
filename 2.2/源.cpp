#include<cstdio>
#include<cmath>
#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用

// 问题 A: 例题1-1-1 按要求输出信息(1)
// http://codeup.cn/problem.php?cid=100000566&pid=0
void ex_A() {
	printf("%s", "This is my first c program!");
}

// 问题 B: 例题1-1-2 按要求输出信息(2)
// http://codeup.cn/problem.php?cid=100000566&pid=1
void ex_B(){
	printf("%s", "********************\nVery Good!\n********************");
}

void ex_C() {
	int a = 123, b = 456;
	int sum = a + b;
	printf("sum=%d", sum);
}

//问题 D : 例题1 - 2 - 2 求两整数数之和(2)
void ex_D() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a + b);
}

//问题 E : 例题3 - 5 求一元二次方程的根
void ex_E() {
	double a, b, c;
	a = b = c = 0;
	while (1) {
		if (a == 0 && (b * b - 4 * a * c) <= 0) {
			scanf("%lf %lf %lf", &a, &b, &c);
		}
		else {
			break;
		}
	}
	printf("r1=%7.2f\nr2=%7.2f", (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a), (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));

}

//问题 F : 例题3 - 9 字符输入输出
void ex_F_1() {
	char a = getchar();
	char b = getchar();
	char c = getchar();
	getchar();
	putchar(a);
	putchar(b);
	putchar(c);

}
void ex_F_2() { // 这个貌似有bug，还没有调试过
	char a[3];
	for (int i = 0; i < 3; i++) {
		a[i] = getchar();
	}
	a[3] = '\0'; // 注意必须强制添上结束符
	printf("%s", a);
}

int main()
{
	//ex_A();
	//ex_B();
	//ex_C();
	//ex_D();
	//ex_E();
	//ex_F_1();
	ex_F_2();

	return 0;
}