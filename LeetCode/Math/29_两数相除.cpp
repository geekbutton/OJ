// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
29. 两数相除
https://leetcode-cn.com/problems/divide-two-integers/description/

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
如果除法结果溢出，则返回 2^31 − 1。
*/

/*整体思路是 :	因为题目要求不能做除法，所以就利用减法代替除法，因为除法本质上就是一种减法
的形式，但是在这里要注意对INT_MIN的处理。因为INT_MIN是无法直接abs取正的。同时对于除数为1或-1
的情况直接返回被除数节省计算时间。
*/
class Solution {
public:
	int divide(int dividend, int divisor) {
		int result = 0;
		if (!dividend)
			return 0;
		//除数被除数都大于0或小于0，则可以直接做减法，唯一的例外是INT_MIN/-1，此时溢出
		//因此返回INT_MIN，这也是唯一可能产生溢出的情况
		if (dividend > 0 && divisor > 0 || (dividend < 0 && divisor < 0)) {
			if (dividend > 0) {
				if (divisor == 1)
					return dividend;
				while (dividend > 0) {
					dividend -= divisor;
					++result;
				}
			}
			else {
				if (dividend == INT_MIN && divisor == -1)
					return INT_MAX;
				while (dividend < 0) {
					dividend -= divisor;
					++result;
				}
			}
			return dividend == 0 ? result : result - 1;
		}//被除数大于0，除数小于0，如果除数为INT_MIN，直接返回0，否则按减法处理，注意返回负值
		else if (dividend > 0 && divisor < 0) {
			if (divisor == INT_MIN)
				return 0;
			divisor = abs(divisor);
			if (divisor == 1)
				return -1 * dividend;
			while (dividend > 0) {
				dividend -= divisor;
				++result;
			}
			return (dividend == 0 ? result : result - 1) * (-1);
		}//被除数小于0，除数大于0，此时不需要判断INT_MIN的情况，直接将除数取负做减法，返回负值
		else if (dividend < 0 && divisor>0) {
			if (divisor == 1)
				return dividend;
			divisor = -1 * divisor;
			while (dividend < 0) {
				dividend -= divisor;
				++result;
			}
			return (dividend == 0 ? result : result - 1)*(-1);
		}
		
	}
};