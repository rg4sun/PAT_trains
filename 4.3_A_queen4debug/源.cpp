#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<cmath>


// 由于主文件8皇后，count更新一直找不出问题，调试起来递归层次太多
// 所以这里用 3皇后 来调试count的更新问题
// ummm 突然发现3皇后 无解
//改成4皇后
int count = 0, p[5], hashTable[5] = { false }; // 由于要取到4，并且从1开始，所以长度设为5

void queen3(int index, int order/*, int count*/) { 
	// 调试的时候终于发现了，这里我傻了又定义了一个count，导致在queen3函数里的count是局部变量，每次return之后会重置为0
	// 这里直接删掉 queen3的count定义就好了，外部已经定义了全局变量了
	if (index == 5) {
		count++; // count更新有问题，放这里的时候，一直是1
		if (count == order) { // 如果是需要输出的皇后串序号
			//printf("the %d queen sequence:\n", count);
			for (int i = 1; i < 5; i++) {
				printf("%d", p[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int x = 1; x <= 4; x++) {
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
				queen3(index + 1, order); // 递归计算下一列
				hashTable[x] = false;// 本行递归完毕，重置本行哈希表
			}
		}
	}
}


int main()
{
	int order;
	scanf("%d", &order);
	queen3(1, order); // 输出当前序号的 皇后串

	return 0;
}