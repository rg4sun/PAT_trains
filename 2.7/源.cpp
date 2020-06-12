#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

// 问题 A: C语言10.1
// ummm 这题目。，。好没有意思
void big_swap(int* a, int* b) { // 注意，C++自带swap函数！！不要重名了！！
	if (*a < *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
void ex_a() {
	int a, b;
	cin >> a >> b;
	big_swap(&a, &b);
	cout << a << " " << b;
}

// 问题 B: C语言10.2
void ex_b() {
	int a, b, c;
	cin >> a >> b >> c;
	big_swap(&a, &b); // 保证a>b
	big_swap(&a, &c); // 保证a>c
	big_swap(&b, &c); // 保证b>c
	cout << a << " " << b << " " << c << endl;

}

// 问题 C: C语言10.10
void ex_c() {
	const char* a = "I love China!"; // VS2019,cpp文件中不能 char* a = "abc";一定要加const
	int n = 100;
	while (!(n >= 0 && n < 13)) {
		cin >> n;
	}
	char* b = (char*)malloc(strlen(a) * sizeof(char));
	strcpy(b, a + n);
	cout << b << endl;

}
// 有个问题, 用 bool p = n >= 0 && n < 13; 来判断，怎么就一直再循环？
// ummm傻了，while里面没有更新 p命题
void ex_c_err() {
	const char* a = "I love China!"; // VS2019,cpp文件中不能 char* a = "abc";一定要加const
	int n = 100;
	bool p = n >= 0 && n < 13;
	while (!p) {
		cin >> n;
		// p = n >= 0 && n < 13; // 加上这句就好了
	}
	char* b = (char*)malloc(strlen(a) * sizeof(char));
	strcpy(b, a + n);
	cout << b << endl;

}

// 问题 D: C语言10.15
void str_swap_err(char* a, char* b) { 
	// 这个又犯了 指针地址交换的错误，改正见下一个函数
	// 这里的 a b是临时变量，存储了传入指针的地址
	// 在函数里交换 a b，虽然交换了地址
	// 但是出了函数后，并未交换传入指针的地址
	// 详细原因见《算法笔记》p68
	if (strcmp(a, b) > 0) {
		char* tmp = a;
		a = b;
		b = tmp;
	}
}

void str_swap_err0(char*& a, char*& b) {
	// 这里加了引用，传入的时候就是直接操作原本的指针变量
	// 详细原因见《算法笔记》p69 - 指针的引用
	// 但是还是不行
	if (strcmp(a, b) > 0) {
		char* tmp = a;
		a = b;
		b = tmp;
	}
}

//void ex_d_err0() {
//	char* a[512], b[512], c[512];
//	scanf("%s\n%s\n%s", a, b, c);
//	str_swap_err0(a, b);
//	//无法用 "char *[512]" 类型的值初始化 "char *&" 类型的引用(非常量限定)
//}

// 或者不交换指针地址，可以借助strcpy交换指针指向的字符串内容
void str_swap(char* a, char* b) {
	if (strcmp(a, b) > 0) {
		char* tmp = (char*)malloc(strlen(a) * sizeof(char));
		strcpy(tmp, a);
		strcpy(a, b);
		strcpy(b, tmp);
	}
}

// 或者用string
void str_swap1(string& a, string& b) {
	if (a > b) {
		string tmp = a;
		a = b;
		b = tmp;
	}
}

void ex_d_err() { // 感觉可能不让用string
	string a, b, c;
	// 题目要求：保证每个字符串的长度不超过20
	while (1) {
		cin >> a >> b >> c;
		bool p = a.length() <= 20 && b.length() <= 20 && c.length() <= 20;
		if (p) {
			break;
		}
	}
	// 方法一
	str_swap((char*)a.c_str(), (char*)b.c_str()); // 保证a<b
	str_swap((char*)a.c_str(), (char*)c.c_str()); // 保证a<c
	str_swap((char*)b.c_str(), (char*)c.c_str()); // 保证b<c
	// 方法二, 但是没有用指针，题目说要用指针
	//str_swap1(a, b);
	//str_swap1(a, c);
	//str_swap1(b, c);
	cout << a << endl << b << endl << c << endl;

}

void ex_d() { // 果然，不用string了就正确了
	char a[20], b[20], c[20];
	while (1) {
		scanf("%s\n%s\n%s", a, b, c);
		bool p = strlen(a) <= 20 && strlen(b) <= 20 && strlen(c) <= 20;
		if (p) {
			break;
		}
	}
	str_swap(a, b);
	str_swap(a, c);
	str_swap(b, c);
	printf("%s\n%s\n%s", a, b, c);
}

// 问题 E: C语言10.16
void input(int a[]) {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
}

void deal(int a[]) {
	int max = 0, min = 0;
	for (int i = 1; i < 10; i++) {
		if (a[i] > a[max]) {
			max = i;
		}
		if (a[i] < a[min]) {
			min = i;
		}
	}
	int tmp = a[0];
	a[0] = a[min];
	a[min] = tmp;
	
	tmp = a[9];
	a[9] = a[max];
	a[max] = tmp;
}

void output(int a[]) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}

void ex_e() {
	int a[10];
	input(a);
	deal(a);
	output(a);
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