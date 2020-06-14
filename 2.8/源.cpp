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

void ex_a0() { // 本机运行没问题，但是codeup编译一直显示编译中，下面不用string改用char* ; 等下，好像是因为n没初始化
	int n;
	scanf("%d", &n); // 加上这句应该可以，之前未加这句
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

// 问题 C: C语言11.4
// C/C++中的联合体union介绍 
// https://blog.csdn.net/mooneve/article/details/92703036
// 我参考了《C语言程序设计现代方法第二版》中union的知识
// 简言之，union和struct的唯一区别是
// struct的成员有自己单独的内存空间，而union的成员共享最大成员的内存空间（union其中任一成员改值都会影响别的成员）
struct member{
	int num;
	char name[10];
	char sex;
	char job;
	union {
		int classID;
		char position[10];
	}category;
};

void ex_c() {
	int n=110;
	while (n > 100) {//保证n不超过100
		scanf("%d", &n);
	}
	member* m = (member*)malloc(n * sizeof(member));
	for (int i = 0; i < n; i++) {
		scanf("%d", &(m + i)->num);
		while (1) {//保证每一个人名都不包含空格且长度不超过9
			scanf("%s", (m + i)->name);
			if (strlen((m + i)->name) > 9)
				continue;
			for (int i = 0; i < strlen((m + i)->name); i++) {
				if ((m + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		while (true) {// 保证性别用m和f两个字符来表示
			scanf("%c", &(m + i)->sex);
			bool p = (m + i)->sex == 'm' || (m + i)->sex == 'f';
			if (!p)
				continue;
			break;
		}
		while (true) {// 保证job用s和t两个字符来表示
			scanf("%c", &(m + i)->job);
			bool p = (m + i)->job == 's' || (m + i)->job == 't';
			if (!p)
				continue;
			break;
		}
		if ((m + i)->job == 's') {
			scanf("%d", &(m + i)->category.classID);
		}
		else {
			while (1) {//保证职务长度不超过9的无空格字符串
				scanf("%s", (m + i)->category.position);
				if (strlen((m + i)->category.position) > 9)
					continue;
				for (int i = 0; i < strlen((m + i)->category.position); i++) {
					if ((m + i)->category.position[i] == ' ')
						continue;
				}
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d %s %c %c ", (m + i)->num, (m + i)->name, (m+ i)->sex, (m + i)->job);
		if ((m + i)->job == 's') {
			printf("%d\n", (m + i)->category.classID);
		}
		else {
			printf("%s\n", (m + i)->category.position);
		}
	}

}

// 问题 D: C语言11.7
struct Student_D {
	int id;
	char name[20];
	int grades[3];
};

void input(Student_D s[]) {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &(s+i)->id);
		while (1) {// 名字（长度不超过19的无空格字符串）
			scanf("%s", (s + i)->name);
			if (strlen((s + i)->name) > 19)
				continue;
			for (int i = 0; i < strlen((s + i)->name); i++) {
				if ((s + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		for (int j = 0; j < 3; j++) { //3门课程的成绩（0至100之间的整数）
			while (scanf("%d", &(s + i)->grades[j]), (s + i)->grades[j] <0 || (s + i)->grades[j] > 100) {
				// do nothing
			}
		}
		
	}
}

void print(Student_D s[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d %s %d %d %d\n", (s + i)->id, (s + i)->name,
			(s + i)->grades[0], (s + i)->grades[1], (s + i)->grades[2]);
	}
}

void ex_d() {
	Student_D s[5];
	input(s);
	print(s);

}

// 问题 E: C语言11.8
struct Student_E {
	int id;
	char name[20];
	int grades[3];
	double avg_grade;
};

void input_e(Student_E s[], int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &(s + i)->id);
		while (1) {// 名字（长度不超过19的无空格字符串）
			scanf("%s", (s + i)->name);
			if (strlen((s + i)->name) > 19)
				continue;
			for (int i = 0; i < strlen((s + i)->name); i++) {
				if ((s + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		(s+i)->avg_grade = 0;
		for (int j = 0; j < 3; j++) { //3门课程的成绩（0至100之间的整数）
			while (scanf("%d", &(s + i)->grades[j]), (s + i)->grades[j] < 0 || (s + i)->grades[j] > 100) {
				// do nothing
			}
			(s + i)->avg_grade += (s + i)->grades[j];
		}
		(s + i)->avg_grade /= 3;
	}
}



void ex_e() {
	Student_E s[3];
	int n = 10;
	input_e(s, n);
	int max = 0;
	double grade_avg[3] = { 0,0,0 };
	for (int i = 0; i < n; i++) {
		if (s[max].avg_grade < s[i].avg_grade)
			max = i;
		grade_avg[0] += (double)s[i].grades[0];
		grade_avg[1] += (double)s[i].grades[1];
		grade_avg[2] += (double)s[i].grades[2];
	}
	for (int i = 0; i < 3; i++) {
		printf("%.2f ", grade_avg[i] /= n);
	}
	printf("\n%d %s %d %d %d\n", (s + max)->id, (s + max)->name,
		(s + max)->grades[0], (s + max)->grades[1], (s + max)->grades[2]);

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