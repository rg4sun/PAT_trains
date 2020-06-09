#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

void ss_inOut_test() {
	int n;
	char str[100] = "123";
	sscanf(str, "%d", &n);
	printf("%d\n", n);
	n = 99;
	sprintf(str, "%d", n);
	printf("%s\n", str);
}

void bubble_sort(int a[], int len, int reverse=0) {
	for (int i = 1; i <= len - 1; i++) {
		for (int j = 0; j < len - i; j++) {
			if (reverse) {
				if (a[j] < a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
			else {
				if (a[j] > a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
		}
	}
}

// 问题 A: 习题6-4 有序插入
void ex_a() {
	int a[10];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &a[9]);
	bubble_sort(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}


// 问题 B: 习题6-5 数组元素逆置
void reverse_array(int a[], int len) {
	// 思想直接交换数组首尾，奇数中间的和自己交换也就是不交换，刚好交换次数是[len/2] 取整
	for (int i = 0; i < len / 2; i++) {
		int tmp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tmp;
	}
}

void ex_b() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	reverse_array(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

}

// 问题 C: 习题6-6 杨辉三角
// 这题我用 组合数来做
// 因为杨辉三角的每一层就是组合数的展开
int factoria(int n) {
	int f = 1;
	for (int i = 1; i <= n; i++) { // n=0时候，不执行for，直接return f=1
		f *= i;
	}
	return f;
}
int combination(int m, int n) {
	return factoria(n) / (factoria(m) * factoria(n - m));
}

void ex_c() {
	int n;
	scanf("%d", &n);
	for (int k = 0; k < n; k++) {
		for (int i = 0; i <= k; i++) {
			printf("%d ", combination(i, k));
		}
		printf("\n");
	}
}

// 问题 D: 习题6-12 解密
// 这题是非常简单的 代换（替换）密码的实现
// 注意代换密码 和 置换密码 区别
// 代换是在一个字符集上进行映射替换，而置换是在明文基础上进行换位
// 这题一个比较直接的思路是 将字符集直接定义成数组，通过数组下标索引进行代换规则
// 但是，可以直接利用asccii码表

char decode(char encode_chr) {
	bool p = encode_chr >= 'A' && encode_chr <= 'Z';
	bool q = encode_chr >= 'a' && encode_chr <= 'z';
	if (!(p || q)) { // 不是字母的返回本身
		return encode_chr;
	}
	if (encode_chr < 'a')
		return 'Z' - (encode_chr - 'A');
	return 'z' - (encode_chr - 'a');
}

void ex_d() {
	string cipher;
	cin >> cipher;
	for (int i = 0; i < cipher.length(); i++) {
		cipher[i] = decode(cipher[i]);
	}
	cout << cipher;
}

//问题 E: 习题6-13 字符串比较
int RG_strcmp(char str1[], char str2[]) {
	char* p1 = str1;
	char* p2 = str2;
	int cmp = 0;
	while (*p1 != '\0' && *p2 != '\0'){
		cmp = *p1 - *p2;
		if (cmp == 0) {
			p1 += 1;
			p2 += 1;
		}
		else {
			return cmp;
		}
	}
}
// 关于 c++ string转char
// https://www.cnblogs.com/mdumpling/p/8179167.html
// https://www.cnblogs.com/wuruofeng/p/10412559.html
void ex_e() { // 哦，好像不能这样，题目规定必须用gets()读入字符
	string a, b;
	cin >> a;
	cin >> b;
	// const char* c_a = a.c_str();
	//char* pa = (char*)malloc(a.length() * sizeof(char));
	//char* pb = (char*)malloc(b.length() * sizeof(char));
	//pa = (char*)a.c_str();
	//pb = (char*)b.c_str();
	//printf("%d", RG_strcmp(pa, pb));
	printf("%d", RG_strcmp((char*)a.c_str(), (char*)b.c_str()));
}
// 或者粗暴点，直接开辟两个大数组
void ex_e_vio() {
	char a[512], b[512];
	gets_s(a, 512);
	gets_s(b, 512);
	printf("%d", RG_strcmp(a, b));
}

// 问题 F: 例题6-1 逆序输出数组元素
// 这题。，。就是 c题目

// 问题 G: 例题6-2 数组求解Fibonacci数列问题
int fibo(int n) { 
	if (n < 3) {
		return 1;
	}
	else {
		int a = 1, f = 2;
		for (int i = 0; i < n - 3; i++) {
			int tmp;
			tmp = a;
			a = f;
			f += tmp;
		}
		return f;
	}
}

void ex_g() {
	for (int i = 1; i < 21; i++) {
		printf("%d\n", fibo(i));
	}
}

// 问题 H: 例题6-3 冒泡排序
// A题实现过，直接用就完事了
void ex_h() {
	int a[10];
	for (int i=0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	bubble_sort(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}

// 问题 I: 例题6-4 矩阵转置
// void f(int a[][]) // 非法，二维数组第二维必须指定
// void f(int** a)  // 这个可以
// 我觉得可以用一维数组模拟二维数组，这样就不会有嵌套for，复杂度也不高
// 这里就先无脑写了最直接的思路
void transposition_err(int** a, int m, int n) { // 有问题，a的地址不会被改掉
	int** tmp = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		tmp[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[j][i];
		}
	}
	a = tmp; // 明明使得a指向tmp了，调试的时候也对的
	// 但是一旦函数返回了，a又不是指向tmp了，这是为啥
	// 我猜测：tmp的生存域仅在此函数内，出了该函数内存就被回收了
	// 所以a在函数返回后会指向哪？这里的测试是又变回原来的地址了
	// https://blog.csdn.net/u010954806/article/details/23127371
}
void ex_i_err() {
	//int a[2][3]; //  "int (*)[3]" 类型的实参与 "int **" 类型的形参不兼容
	// transposition(int** a, int m, int n)
	// 看来 二维数组和二维指针还是有所区别的
	int m = 2, n = 3;
	int** a = (int**)malloc(m * sizeof(int*));
	// 发现一个现象，二维指针，a和a+1的地址不是连续的
	// a[0][0]-[2]连续，a[1][0]-[2]连续，但是a[0][2]的下一个地址不是a[1][0]
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	transposition_err(a, 2, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
// ---------------------------------------------------------
// 经典笨比代码，我怀疑上面的二重指针出现的错误，和这里应该类似
void to1(int* x) {
	int a = 1;
	int* tmp = &a;
	x = tmp;
}

void test() {
	int a = 10;
	int* p = &a;
	to1(p);
	printf("%d", *p);
}
// ---------------------------------------------------------


// 一个很简单的解决方法, 直接传入一个指针用于接收就好
void transposition(int** a, int m, int n, int **a_t) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a_t[i][j] = a[j][i];
		}
	}
}

void ex_i() {
	//int a[2][3]; //  "int (*)[3]" 类型的实参与 "int **" 类型的形参不兼容
	// transposition(int** a, int m, int n)
	// 看来 二维数组和二维指针还是有所区别的
	int m = 2, n = 3;
	int** a = (int**)malloc(m * sizeof(int*));
	// 发现一个现象，二维指针，a和a+1的地址不是连续的
	// a[0][0]-[2]连续，a[1][0]-[2]连续，但是a[0][2]的下一个地址不是a[1][0]
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int** a_t = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a_t[i] = (int*)malloc(m * sizeof(int));
	}
	transposition(a, 2, 3, a_t);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a_t[i][j]);
		}
		printf("\n");
	}
}

// 稍微好看些
int** transposition_1(int** a, int m, int n) {
	int** tmp = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		tmp[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[j][i];
		}
	}

	return tmp;
}
void ex_i_1() {
	//int a[2][3]; //  "int (*)[3]" 类型的实参与 "int **" 类型的形参不兼容
	// transposition(int** a, int m, int n)
	// 看来 二维数组和二维指针还是有所区别的
	int m = 2, n = 3;
	int** a = (int**)malloc(m * sizeof(int*));
	// 发现一个现象，二维指针，a和a+1的地址不是连续的
	// a[0][0]-[2]连续，a[1][0]-[2]连续，但是a[0][2]的下一个地址不是a[1][0]
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	a = transposition_1(a, 2, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	//ss_inOut_test();
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	//ex_e();
	//ex_g();
	//ex_h();
	//ex_i();
	ex_i_1();



	return 0;
}