// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
7. 反转整数
https://leetcode-cn.com/problems/reverse-integer/description/

给定一个 32 位有符号整数，将整数中的数字进行反转。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
根据这个假设，如果反转后的整数溢出，则返回 0。
*/

/*整体思路是 :	通过将数字转换为字符串，再将字符串反转，反转完成后重新转换为数字。要注意的
是要对反转后的字符串进行判断，判断其是否会产生溢出，只在不会产生溢出的情况利用stoi获得对应整数。
*/
class Solution {
public:
	int reverse(int x) {
		string I_MAX = "2147483647", I_MIN = "-2147483648";	//设置的上下限阈值
		string value = to_string(x);
		if (x < 0)	//注意对负值，仅反转负号之后的字符
			std::reverse(value.begin() + 1, value.end());
		else
			std::reverse(value.begin(), value.end());
		//按照x取值的正负分别判断反转后的数字是否会溢出
		if (x > 0 && value.size() == I_MAX.size() && value > I_MAX)
			return 0;
		if (x < 0 && value.size() == I_MIN.size() && value>I_MIN)
			return 0;
		int result = stoi(value);	//将字符串转换为数字作为结果返回
		return result;
	}
};