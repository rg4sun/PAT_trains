#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>

//inline void test_err() {
//	int n;
//	while (1) {
//		scanf("%d", &n);
//		if (n <= 100000) {
//			break;
//		}
//	}
//	int school[10001] = { 0 };
//	int maxID = 0;
//	for (int i = 0; i < n; i++) {
//		int id, score;
//		scanf("%d %d", &id, &score);
//		school[id] += score;
//		if (school[maxID] < school[id]) {
//			maxID = id;
//		}
//	}
//	printf("%d %d", maxID, school[maxID]);
//}

//以上代码报了 段错误
// PAT 段错误的原因和解决方法：
// https://blog.csdn.net/qq_41325698/article/details/97903937

//int school[10001] = { 0 }; // 大数组一定要开全局，而不是写在main函数里面
// 10^5=100000 有5个0

//extern int school[100001] = { 0 };

inline void test() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n <= 100000) {
			break;
		}
	}
	int school[100001] = { 0 };
	int maxID = 0;
	for (int i = 0; i < n; i++) {
		int id, score;
		scanf("%d %d", &id, &score);
		school[id] += score;
		if (school[maxID] < school[id]) {
			maxID = id;
		}
	}
	printf("%d %d", maxID, school[maxID]);
}

// ummmmm，结果发现不是上面的原因，把数组再开大点就好了【不过还是建议把大数组定义成全局】
//因为⼤数组 在 main 函数⾥⾯的话是存储在栈⾥，⽽栈空间是在进程创建时初始化的，有固定的⼤⼩，
//⼀ 般为⼏⼗KB，所以太⼤的数组会耗光栈空间。⽽全局变量占⽤的堆空间，堆空间中的内存是按 需分配，
//⾃由增⻓的，可以⾮常⼤，⽐如32位的系统中可以⼤到4GB。将⼤数组放在全局变量中 能避免栈溢出