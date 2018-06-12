// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
85. 最大矩形
https://leetcode-cn.com/problems/maximal-rectangle/description/

给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
*/

/*整体思路是 :	利用跟84题一样的解题思路来解决。首先处理第一行求得最大面积，再将第二行
拼接至第一行上，注意当新的一行对应位置为0时，则合并时仍然为0，否则++。
*/
void max_rectangle(vector<int>&, int&);
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<int> iv(matrix[0].size(), 0);
		int result = matrix[0][0] - '0';
		//从第一行开始逐行按照84题解法求解一维最大矩形问题
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				//如果新元素为0，则整体置0，否则++
				iv[j] = (matrix[i][j] - '0') ? (iv[j] + 1) : 0;
			}
			max_rectangle(iv, result);
		}
		return result;
	}
};
//同84题解决方案
void max_rectangle(vector<int>& matrix, int& result) {
	matrix.push_back(0);		//末尾加0，确保所有元素都会出栈
	stack<int> is;
	is.push(0);
	for (int i = 1; i < matrix.size(); ++i) {
		//注意判断条件，同时注意栈中存储的为索引，而非对应值
		if (is.empty() || matrix[i] >= matrix[is.top()]) {
			is.push(i);
			continue;
		}
		while (!is.empty() && matrix[i] < matrix[is.top()]) {
			int index = is.top();
			int value = matrix[index];
			is.pop();
			result = max(result, value*(is.empty() ? (i) : (i - 1 - is.top())));
		}
		is.push(i);
	}
	matrix.pop_back();
	return;
}