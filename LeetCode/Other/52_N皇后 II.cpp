// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
52. N皇后 II
https://leetcode-cn.com/problems/n-queens-ii/description/

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。

*/

/*整体思路是 :	这道题非常重要也非常经典，是一道典型的回溯算法的问题。其解答同51题一样，只是
把对答案的记录改成了一个计数值用来统计可行的结果数，算法没有任何差别。
*/
void Queens(int, int, int*, vector<int>, vector<int>, vector<int>);
class Solution {
public:
	int totalNQueens(int n) {
		int result = 0;
		vector<int> rows(n), cols(n);		//设置的四个vector，其实只用到后三个用来标记是否可在某位置放置一个皇后
		vector<int> left_line(2 * n - 1), right_line(2 * n - 1);
		vector<string> value;
		Queens(0, n, &result, cols, left_line, right_line);
		return result;
	}
};

void Queens(int level, int n, int* result,vector<int> cols, vector<int> left_line, vector<int> right_line) {
	for (int i = 0; i < n; ++i) {
		if (cols[i])
			continue;
		int left_index = 0, right_index = 0;
		if (level <= i) {	//判断左右对角线上能否放置
			left_index = i + level;
			right_index = i - level + (n - 1);
		}
		else {
			left_index = level + i;
			right_index = (n - 1) - (level - i);
		}
		if (left_line[left_index] || right_line[right_index])
			continue;

		cols[i] = 1; left_line[left_index] = 1; right_line[right_index] = 1;
		if (level < n - 1) {
			Queens(level + 1, n, result, cols, left_line, right_line);
			cols[i] = 0; left_line[left_index] = 0; right_line[right_index] = 0;
		}
		else
			++*result;
	}
}

