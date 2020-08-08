#pragma once
#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<cmath>


// 由于主文件8皇后，count更新一直找不出问题，调试起来递归层次太多
// 所以这里用 3皇后 来调试count的更新问题
// 调试时需要注释掉 源.cpp中下面这一行
//int count = 0, p[4], hashTable[4] = { false }; // 由于要取到3，并且从1开始，所以长度设为4
void queen3(int index, int order, int count) {
	if (index == 4) {
		//count++; // count更新有问题，放这里的时候，一直是1
		if (1) { // 如果是需要输出的皇后串序号
			printf("the %d queen sequence:\n", count);
			for (int i = 1; i < 4; i++) {
				printf("%d", p[i]);
			}
			printf("\n");
		}
		//count++;
		return;
	}
	for (int x = 1; x <= 3; x++) {
		if (hashTable[x] == false) {// x行还没有皇后
			bool notCollision = true; // true表示当前皇后与之前皇后不冲撞
			for (int pre = 1; pre < index; pre++) {
				// 当前皇后列号为index，行号为x；遍历所有先前的皇后
				// 先前皇后列号为pre，行号为p[x]
				if (abs(index - pre) == abs(x - p[pre])) {// 冲突
					notCollision = false;
					break; // 当前x出现冲撞，跳出循环，检验下一个x
				}
			}
			if (notCollision) {// 不冲撞，则当前x可以存入序列
				p[index] = x;
				hashTable[x] = true;
				queen3(index + 1, order, count); // 递归计算下一列
				hashTable[x] = false;// 本行递归完毕，重置本行哈希表
			}
		}
	}
}


void queen4debug()
{
	int order;
	scanf("%d", &order);
	queen3(1, order, count); // 输出当前序号的 皇后串

}