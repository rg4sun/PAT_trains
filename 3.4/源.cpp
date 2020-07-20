#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>

// 问题 A: 日期差值

bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100))
		return true;
	return false;
}

int daysOfMonth(int year, int month) {
	if (month == 0)
		return 0;
	else if (month == 2) {
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;

}

int interval_days(int date1, int date2) {
	if (date1 > date2) {
		int tmp = date1;
		date1 = date2;
		date2 = tmp;
	}
	return 0;
}

void ex_a() {

}

int main()
{
	printf("%d", daysOfMonth(2020, 2));
	return 0;
}