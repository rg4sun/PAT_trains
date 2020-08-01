#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct Student
{
	//int id; int存储不了 13位的数字
	//string id; // 之前出现一些乱码问题，改成char
	char id[15];
	int location;
	int grade;
	int local_rank;//可以不设置总排名，总排名通过整体数组排序得到(但是并列排名就还要处理)
	int total_rank;//所以还是设置一个总排名吧。，。
};

inline void selectSort(Student stu[], int amount) {
	for (int i = 0; i < amount; i++) {
		int k = i;
		for (int j = i; j < amount; j++) {
			if (stu[j].grade > stu[k].grade) {
				k = j;
			}
			//else if (stu[j].grade == stu[k].grade && stu[j].id < stu[k].id) {
				// 分数相同按照id先后排序（升序），思考一个问题 c++ string可以直接比较大小吗
				// C++ 可以直接比较
			else if (stu[j].grade == stu[k].grade && strcmp(stu[j].id, stu[k].id) < 0) {
				k = j;
			}
		}
		// 思考一个问题，结构体可以直接赋值吗？可以
		Student tmp = stu[i];
		stu[i] = stu[k];
		stu[k] = tmp;
	}
}

inline void showStu(Student stu[], int amount) {
	for (int i = 0; i < amount; i++) {
		cout << stu[i].id << ' ' << stu[i].grade << ' ' << stu[i].location << ' ' << stu[i].local_rank << endl;
	}
}

inline void calcRank(Student stu[], int amount, bool localOrTotal) {
	if (localOrTotal) {
		stu[0].local_rank = 1;
		for (int i = 1; i < amount; i++) {
			// 考场排名计算
			if (stu[i].grade == stu[i - 1].grade) {// 分数与上一名一样则排名取上一位
				stu[i].local_rank = stu[i - 1].local_rank;
			}
			else {// 不一样则排名就是当前序号
				stu[i].local_rank = i;
			}
		}
	}
	else {
		stu[0].total_rank = 1;
		for (int i = 1; i < amount; i++) {
			// 总排名计算
			if (stu[i].grade == stu[i - 1].grade) {// 分数与上一名一样则排名取上一位
				stu[i].total_rank = stu[i - 1].total_rank;
			}
			else {// 不一样则排名就是当前序号
				stu[i].total_rank = i;
			}
		}
	}
}

inline void test() {
	int n; // 考场数量
	scanf("%d", &n);
	Student stu[10 * 10 * 10 * 10];
	memset(stu, 0, sizeof(stu));// 整体置为0
	int amount = 0;// 记录总人数
	for (int i = 1; i <= n; i++) {
		int k; // 考场中考生数量
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			/*cin >> stu[amount].id;*/
			scanf("%s %d", stu[amount].id, &stu[amount].grade);
			stu[amount].location = i;
			amount++;
		}
		// 这里完成了一个考场的数据录入，在此马上对这个考场进行排序
		selectSort(stu + amount - k, k); // 这里是 指针头的计算，每个考场的第一个考生地址
		calcRank(stu + amount - k, k, true);// 计算考场排名

	}
	selectSort(stu, amount);// 整体排序
	calcRank(stu, amount, false);// 计算总排名
	showStu(stu, amount);

	return;
}