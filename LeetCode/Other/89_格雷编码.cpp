// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
89. 格雷编码
https://leetcode-cn.com/problems/gray-code/description/

格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
*/

/*整体思路是 :	第一种解法是百度来的，利用格雷码的相关性质得到的格雷码与二进制的转换公式，
利用公式进行求解。第二种解法适用性更强，利用递归和一个无序set来求解。
*/
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		for (int i = 0; i < pow(2, n); ++i) {
			result.push_back((i >> 1) ^ i);
		}
		return result;
	}
};

void CheckGray(int, int, unordered_set<int>&, vector<int>&);
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result{ 0 };
		unordered_set<int> is;
		is.insert(0);
		CheckGray(0, n, is, result);
		return result;
	}
};

void CheckGray(int x, int n, unordered_set<int>& is, vector<int>& result) {
	int i = 0;
	for (; i < n; ++i) {		//每次在当前数字的二进制表示中挑一位取反，判断是否出现过
		int value = x ^ (1 << i);
		if (is.find(value) != is.end())
			continue;
		//没有出现过则添加该数字，并以该数作为基准继续递归
		result.push_back(value);
		is.insert(value);
		CheckGray(value, n, is, result);
	}
	//注意这里的退出条件，遍历所有可能的数字取反都已在set中存在，则说明已遍历完成
	if (i == n)
		return;
}