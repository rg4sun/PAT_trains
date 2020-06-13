#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

// 问题 A: C语言11.1
// C++中string、char *、char[]的转换
// https://www.cnblogs.com/wuruofeng/p/10412559.html
struct person {
	char name[20];
	int count;
}leader[3] = { "Li",0,"Zhang",0,"Fun",0 };

void ex_a0() { // 本机运行没问题，但是codeup编译一直显示编译中，下面不用string改用char*
	int n;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == string(leader[0].name) ){
			leader[0].count += 1;
		}
		else if (tmp == string(leader[1].name) ){
			leader[1].count += 1;
		}
		else if (tmp == string(leader[2].name)){
			leader[2].count += 1;
		}
		tmp.clear(); // 清空字符串内容
	}
	for (int i = 0; i < 3; i++) {
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}
}

void ex_a() { // 果然，不用string编译判断要快很多
	int n;
	char tmp[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		if (strcmp(tmp,leader[0].name) == 0) {
			leader[0].count += 1;
		}
		else if (strcmp(tmp, leader[1].name) == 0) {
			leader[1].count += 1;
		}
		else if (strcmp(tmp, leader[2].name) == 0) {
			leader[2].count += 1;
		}
		strcpy(tmp, "");// 清空字符串内容
		//tmp.clear(); // 清空字符串内容
	}
	for (int i = 0; i < 3; i++) {
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}
}

// 问题 B: C语言11.2
struct student {
	int num;
	char name[20];
	char sex;
	int age;
};

void ex_b() {
	int n=100;
	while (n > 20)
	{
		scanf("%d", &n);
	}
	student* s = (student*)malloc(n * sizeof(student));
	for (int i = 0; i < n; i++) {
		scanf("%d", &(s+i)->num);
		while (1) {//保证每一个人名都不包含空格且长度不超过15
			scanf("%s", (s + i)->name);
			if (strlen((s + i)->name) > 15)
				continue;
			for (int i = 0; i < strlen((s + i)->name); i++) {
				if ((s + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		while (true){// 保证性别用M和F两个字符来表示
			scanf("%c", &(s + i)->sex);
			bool p = (s + i)->sex == 'M' || (s + i)->sex == 'F';
			if (!p)
				continue;
			break;
		}
		scanf("%d", &(s + i)->age);
	}
	for (int i = 0; i < n; i++) {
		printf("%d %s %c %d\n", (s + i)->num, (s + i)->name, (s + i)->sex, (s + i)->age);
	}
}

int main()
{
	//ex_a();
	ex_b();

	return 0;
}