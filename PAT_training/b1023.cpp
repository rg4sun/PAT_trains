#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>

inline void test() {
	int numTable[10] = { 0 };
	int count = 0; // 记录总共有几个数
	for (int i = 0; i < 10; i++) {
		scanf("%d", &numTable[i]);
		count += numTable[i];
	}
	int* output = (int*)malloc(count * sizeof(int));
	// 其实，整个numTable是排序好的，由于首字母不为0，所以只需要把第一个比0大的数移到第一位就好了
	// 实现方式：先把numTable中的数放入output，如 001117889
	int index = 0; // 下标指示器，记录当前在output中的下标
	for (int num = 0; num < 10; num++) {
		for (int numAmount = 0; numAmount < numTable[num]; numAmount++) {// 不是numAmount <= numTable[num]
			output[index++] = num;
			//output[index] = num;
			//index++;
		}
	}
	// 在判断首字符是不是0，是的话则找到第一个比0大的数与首字符交换
	if (output[0] == 0) {
		for (int i = 1; i < count; i++) {
			if (output[i] != 0) {
				output[0] = output[i];
				output[i] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%d", output[i]);
	}
}