#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>


inline int getID(char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

inline void test() {
	// "const char *" 类型的值不能用于初始化 "char *" 类型的实体的三种解决方法
	// https://www.cnblogs.com/xiximayou/p/12121287.html
	//char* name = "ZOE1";
	char name[] = "ZOE1";
	printf("%d\n", getID(name));

}