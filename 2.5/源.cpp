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

int main()
{
	//ss_inOut_test();
	//ex_a();
	//ex_b();
	//ex_c();
	ex_d();



	return 0;
}