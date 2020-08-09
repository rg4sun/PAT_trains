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

inline bool cmp(MoonCake a, MoonCake b) {// sort用的比较函数，按照单价从高到低排序
	return a.price > b.price;
}

inline void test_err() {// 有一组测试用例显示段错误
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
	printf("%.2f", cost);
}

inline void test_still_err() {
	int n; // 月饼种类数、市场最大需求量
	double d; // 市场最大需求量 也改成double型
	// 考虑到可能不是整的，就有0.5吨这样，就不能单纯的d--了
	scanf("%d %lf", &n, &d);
	MoonCake* moonCake = (MoonCake*)malloc(n * sizeof(MoonCake));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalAmount);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalPrice);
		moonCake[i].price = moonCake[i].totalPrice / moonCake[i].totalAmount;
	}
	sort(moonCake, moonCake + n, cmp);
	double cost = 0; // 记录花费
	int cakeId = 0;
	while (d > 0) {
		if (moonCake[cakeId].totalAmount <= d) {// 当前种类月饼有库存 <= 当前剩余需求
			d -= moonCake[cakeId].totalAmount; // 直接减去整个库存
			cost += moonCake[cakeId].totalPrice;
		}
		else {// 当前种类月饼有库存 > 当前剩余需求
			cost += d * moonCake[cakeId].price;
			break; // 别忘记这里必须要跳出，因为已经满足了所有需求
		}
		cakeId++;
	}
	printf("%.2f", cost);
}

inline void test() {
	int n; // 月饼种类数、市场最大需求量
	double d; // 市场最大需求量 也改成double型
	// 考虑到可能不是整的，就有0.5吨这样，就不能单纯的d--了
	scanf("%d %lf", &n, &d);
	MoonCake* moonCake = (MoonCake*)malloc(n * sizeof(MoonCake));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalAmount);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalPrice);
		moonCake[i].price = moonCake[i].totalPrice / moonCake[i].totalAmount;
	}
	sort(moonCake, moonCake + n, cmp);
	double cost = 0; // 记录花费
	int cakeId = 0;
	for (int i = 0; i < n; i++) { // 不知道为啥这里改成 for就完全正确了
		if (moonCake[i].totalAmount <= d) {
			d -= moonCake[i].totalAmount;
			cost += moonCake[i].totalPrice;
		}
		else {
			cost += d * moonCake[i].price;
			break;
		}
	}
	printf("%.2f\n", cost);
}