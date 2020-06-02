#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
	char a[10] = "abc";
	char* b = (char*)malloc(10 * sizeof(char));
	b = "abcd";


	return 0;
}