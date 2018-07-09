// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
51. N皇后
https://leetcode-cn.com/problems/n-queens/description/

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

*/

/*整体思路是 :	这道题非常重要也非常经典，是一道典型的回溯算法的问题。一般来讲回溯算法有递归
实现和非递归实现，这里采用递归的方法来实现。(非递归还没写出来)
*/
void Queens(int, int, vector<vector<string>>&, vector<string>,vector<int>, vector<int>, vector<int>);
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<int> rows(n), cols(n);		//设置的四个vector，其实只用到后三个用来标记是否可在某位置放置一个皇后
		vector<int> left_line(2 * n - 1), right_line(2 * n - 1);
		vector<string> value;
		Queens(0, n, result, value, cols, left_line, right_line);
		return result;
	}
};

void Queens(int level, int n, vector<vector<string>>& result, vector<string> value,
			vector<int> cols, vector<int> left_line, vector<int> right_line) {
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
		string temp(n, '.');
		temp[i] = 'Q';
		value.push_back(temp);
		if (level < n - 1) {
			Queens(level + 1, n, result, value, cols, left_line, right_line);
			cols[i] = 0; left_line[left_index] = 0; right_line[right_index] = 0;
			value.pop_back();
		}
		else
			result.push_back(value);
	}
}

