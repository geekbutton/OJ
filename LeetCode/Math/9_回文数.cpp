// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
9. 回文数
https://leetcode-cn.com/problems/palindrome-number/description/

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
你能不将整数转为字符串来解决这个问题吗？
*/

/*整体思路是 :	因为题目要求不能将数字转换为字符串来解决，因此只能获得数字的最高位，然后
每次判断最高位和最低位是否相等，若想等则减去最高位和最低位继续比较。
*/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int level = 1;
		while (x / level / 10)	//先判断出来x的最高位
			level *= 10;
		while (x / 10) {	//一直循环知道x只剩一位
			if (x % 10 != x / level)	//判断首尾是否相等
				return false;
			//减去首尾元素，同时除10，level对应除100
			x -= x % 10 + x / level*level;	
			x /= 10;
			level /= 100;
		}
		if (level > 1 && x)
			return false;
		return true;
	}
};
//使用字符串的版本，提交发现两版本时间开销接近
class Solution {
public:
	bool isPalindrome(int x) {
		string value = to_string(x);
		for (int i = 0, j = value.size() - 1; i < j; ++i, --j) {
			if (value[i] != value[j])
				return false;
		}
		return true;
	}
};