#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<cstdlib>
#include<algorithm> // 用sort函数
using namespace std;


struct MoonCake
{
	double totalAmount;
	double totalPrice;
	double price;
};

bool cmp(MoonCake a, MoonCake b) {// sort用的比较函数，按照单价从高到低排序
	return a.price > b.price;
}

inline void test() {
	int n, d; // 月饼种类数、市场最大需求量
	scanf("%d %d", &n, &d);
	MoonCake* moonCake = (MoonCake*)malloc(n * sizeof(MoonCake));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalAmount);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalPrice);
		moonCake[i].price = moonCake[i].totalPrice / moonCake[i].totalAmount;
	}
	sort(moonCake, moonCake + n, cmp);
	d = (double)d; // 将需求量强制变成double型
	double cost = 0; // 记录花费
	int cakeId = 0;
	while (d>0) {
		if (moonCake[cakeId].totalAmount > 0) {// 当前种类月饼有库存
			moonCake[cakeId].totalAmount--;
			d--;
			cost += moonCake[cakeId].price;
		}
		else {// 无库存，则cakeId++，换下一贵的月饼
			cakeId++;
		}
	}
	printf("%.2lf", cost);
}