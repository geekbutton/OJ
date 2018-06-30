// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
60. 第k个排列
https://leetcode-cn.com/problems/powx-n/description/

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
给定 n 和 k，返回第 k 个排列。
*/

/*整体思路是 :	按照每一个位长上最多包含的排列组合数及待查找的第k个排列确定当前位上的
数字应该为几。如输入n=4,k=9，则为了确定第一位首先计算(n-1)的阶乘即为6，因此可以确定当前
位的值应该为第（k-1）/6+1大的数，此时即为第2大的数即2，再将k-6。重复这个过程，注意退出条件
当k<=0或者当前位为最后一位时，退出循环。
*/
int fact(int);
class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 1)
			return "1";
		int value = fact(n - 1), temp = n;
		vector<int> iv(n, 1);
		string result;
		while (k > 0 && temp > 1) {	//注意退出条件
			int count = 0, i = 0;	//设定一个count帮助找到第index大的数
			int index = (k - 1) / value + 1;	//计算当前应为第几大数
			for (; i < n; ++i) {
				if (iv[i] == 0)
					continue;
				if (iv[i] == 1) {
					++count;
				}
				if (count == index)
					break;
			}
			iv[i] = 0;		//将第index大的数对应标志位置0，表示已使用
			result += to_string(i + 1);	//添加对应数至结果数组
			k -= (k - 1) / value*value;
			if (temp > 1) {
				value /= (temp - 1);
				--temp;
			}
		}
		if (!k || temp == 1) {	//处理最后一位数
			for (int i = 0; i < n; ++i) {
				if (iv[i] != 0)
					result += to_string(i + 1);
			}
		}
		return result;
	}
};

int fact(int n) {
	if (n == 1)
		return 1;
	return n*fact(n - 1);
}