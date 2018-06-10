// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
66. 加一
https://leetcode-cn.com/problems/plus-one/description/

给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

/*整体思路是 :	本质就是一个十进制加法，注意进位的处理，特别是最高位的进位，
当最高位存在进位时，需要额外增加一个元素在容器的首位置。
*/
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int flag = 1;			//注意，flag表示进位，初始值为1，因为最低位需要加1
		for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
			int value = (*iter + flag) % 10;
			flag = (*iter + flag) / 10;
			*iter = value;
			if (!flag)
				break;
		}

		if (flag) {
			digits.insert(digits.begin(), flag);
		}
		return digits;
	}
};
