// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
62. Unique Paths
https://leetcode-cn.com/problems/unique-paths/description/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/

/*整体思路是 :	动态规划，每一个点的路径之和=其上一点的路径之和+其左边点的路径之和
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> iv(m, vector<int>(n, 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || j == 0) {
					iv[i][j] = 1;				//最上一行和最左一行可能路径都等于1
					continue;
				}
				//每一个点的路径之和=其上一点的路径之和+其左边点的路径之和
				iv[i][j] = iv[i - 1][j] + iv[i][j - 1];
			}
		}
		return iv[m - 1][n - 1];
	}
};
