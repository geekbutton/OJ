// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
50. Pow(x, n)
https://leetcode-cn.com/problems/powx-n/description/

实现 pow(x, n) ，即计算 x 的 n 次幂函数。
说明:
	-100.0 < x < 100.0
	n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/

/*整体思路是 :	最开始的想法是最简单的遍历，也就是遍历n次，得到结果但超时。因此考虑采用递归的
方法来进行求解，即X^n = X^(n/2) * X^(n/2+1)(n>0，n%2)，从而实现log(n)的时间复杂度
*/
double Mypow(double, int);
class Solution {
public:
	double myPow(double x, int n) {
		double result = 0;
		if (!n)
			return 1;
		x = n > 0 ? x : 1 / x;	//n为负时记得将x取倒数
		result = Mypow(x, n);
		return result;
	}
};

double Mypow(double x, int n) {
	if (n == 1 || n == -1)
		return x;
	double result = 1;
	if (n % 2) {
		result *= Mypow(x, n / 2);
		result *= n > 0 ? Mypow(x, n / 2 + 1) : Mypow(x, n / 2 - 1);	//注意区分n的政府
		return result;
	}
	//n为偶数时只用求一个n/2的值，在对结果求平方即可
	result *= Mypow(x, n / 2);		
	result *= result;
	return result;
}