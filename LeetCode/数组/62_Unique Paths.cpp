// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
62. Unique Paths
https://leetcode-cn.com/problems/unique-paths/description/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/

/*����˼·�� :	��̬�滮��ÿһ�����·��֮��=����һ���·��֮��+����ߵ��·��֮��
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> iv(m, vector<int>(n, 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || j == 0) {
					iv[i][j] = 1;				//����һ�к�����һ�п���·��������1
					continue;
				}
				//ÿһ�����·��֮��=����һ���·��֮��+����ߵ��·��֮��
				iv[i][j] = iv[i - 1][j] + iv[i][j - 1];
			}
		}
		return iv[m - 1][n - 1];
	}
};
