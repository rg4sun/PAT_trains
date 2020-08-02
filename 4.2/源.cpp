#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>

//问题 A: 谁是你的潜在朋友
//int bookTable[210] = { 0 }; // 书本编号哈希表
//void ex_a_1() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int* buddy = (int*)malloc(n * sizeof(int));//记录每个人喜欢哪本书
//	for (int i = 0; i < n; i++) {
//		scanf("%d", buddy + i);
//		bookTable[buddy[i]]++;
//	}
//	for (int i = 0; i < n; i++) {
//		//if (bookTable[buddy[i]] == 0)//这样不对，按上面的算法，只要有人喜欢一本书，那至少为1，但是只有一个人喜欢
//		if (bookTable[buddy[i]] == 1)// 所以这里的判断应该这么写
//			printf("BeiJu\n");
//		else
//			//printf("%d\n", bookTable[buddy[i]]);
//			printf("%d\n", bookTable[buddy[i]] - 1);// 同理这里要把自己减去
//	}
//}

void ex_a() { // 由于codeup是多点测试所以接收输入 这里改成循环
			  // 哦 我知道哪里有问题了，他多点测试，我把bookTable放在全局里了，这样一组测试过了，第二组的时候bookTable初始不是全0了
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int bookTable[210] = { 0 }; // 书本编号哈希表
		int* buddy = (int*)malloc(n * sizeof(int));//记录每个人喜欢哪本书
		for (int i = 0; i < n; i++) {
			scanf("%d", buddy + i);
			bookTable[buddy[i]]++;
		}
		for (int i = 0; i < n; i++) {
			//if (bookTable[buddy[i]] == 0)//这样不对，按上面的算法，只要有人喜欢一本书，那至少为1，但是只有一个人喜欢
			if (bookTable[buddy[i]] == 1)// 所以这里的判断应该这么写
				printf("BeiJu\n");
			else
				//printf("%d\n", bookTable[buddy[i]]);
				printf("%d\n", bookTable[buddy[i]] - 1);// 同理这里要把自己减去
		}
		//free(buddy);
	}
}


int main()
{
	ex_a();

	return 0;
}

