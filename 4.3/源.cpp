#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<cmath>

// 问题 D: 八皇后
int count=0, p[9], hashTable[9] = { false }; // 由于要取到8，并且从1开始，所以长度设为9
void queen8(int index, int order) {
	if (index == 9) {
		count++; // count更新有问题，放这里的时候，一直是1,找到问题了，是count重复定义的原因，见调试项目
		if (count == order) { // 如果是需要输出的皇后串序号
			//printf("the %d queen sequence:\n", count);
			for (int i = 1; i < 9; i++) {
				printf("%d", p[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int x = 1; x <= 8; x++) {
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
				queen8(index + 1, order); // 递归计算下一列
				hashTable[x] = false;// 本行递归完毕，重置本行哈希表
			}
		}
	}
}

void ex_d() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			int order;
			scanf("%d", &order);
			queen8(1, order); // 输出当前序号的 皇后串
			for (i = 0; i < 9; i++) { // 哈希表整个重置
				hashTable[i] = false;
			}
			count = 0;
		}
	}
}

void test() {
	int order;
	scanf("%d", &order);
	queen8(1, order); // 输出当前序号的 皇后串
}

int main()
{
	test();
	return 0;
}