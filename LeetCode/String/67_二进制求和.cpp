// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
67. 二进制求和
https://leetcode-cn.com/problems/add-binary/description/

给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。
*/

/*整体思路是 :	本质上和十进制加法没有什么区别，不同之处在于十进制加法是对10求商
和求余，二进制则是对2求商和求余
*/
class Solution {
public:
	string addBinary(string a, string b) {
		int num1 = a.size(), num2 = b.size();
		int flag = 0, i = num1 - 1, j = num2 - 1;
		string result;
		for (; i >= 0 && j >= 0; --i, --j) {
			int value = (a[i] - '0' + b[j] - '0' + flag) % 2;
			flag = (a[i] - '0' + b[j] - '0' + flag) / 2;
			result.insert(0, to_string(value));
		}
		while (i >= 0) {
			int value = (a[i] - '0' + flag) % 2;
			flag = (a[i] - '0' + flag) / 2;
			result.insert(0, to_string(value));
			--i;
		}
		while (j >= 0) {
			int value = (b[j] - '0' + flag) % 2;
			flag = (b[j] - '0' + flag) / 2;
			result.insert(0, to_string(value));
			--j;
		}
		while (flag) {
			int value = flag % 2;
			flag = flag / 2;
			result.insert(0, to_string(value));
		}
		return result;
	}
};