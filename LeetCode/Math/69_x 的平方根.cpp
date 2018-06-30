// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
69. x 的平方根
https://leetcode-cn.com/problems/sqrtx/description/

实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/

/*整体思路是 :	可以直接采用遍历法，最大只需要遍历到46340，因为INT_MAX开根号取整最大为46340。
因此总的时间复杂度为O(n)。也可以采用二分查找法，找到第一个l*l<=x且(l+1)*(l+1)>x的值此时l为最终
结果。
*/
int Binary(int, int, int);
class Solution {
public:
	int mySqrt(int x) {
		//三种特殊情况，x=0,1,大于等于2147395600(大于等于它的数对应开根号都是46340)
		if (x == 0)
			return 0;
		if (x == 1)
			return 1;
		if (x >= 46340 * 46340)
			return 46340;
		return Binary(1, 46340, x);
	}
};

int Binary(int l, int r, int x) {
	//注意，除了查找正好匹配的值外，还要查找最后一个平方小于x的值，对于开根号结果不为
	//整数的情况，不可能找到正好匹配的值，因此取最后一个平方小于x的值
	if (l*l <= x && (l + 1)*(l + 1) > x)
		return l;
	int mid = (r - l) / 2 + l;
	int value = mid*mid;
	if (value == x)
		return mid;
	if (value > x)
		return Binary(l, mid, x);
	return Binary(mid, r, x);
}

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		int i = 1;
		for (; i < x/2; ++i) {
			if (i*i <= x && ((i + 1)*(i + 1) > x || i==46340)) {
				return i;
			}
		}
		return i;
	}
};
