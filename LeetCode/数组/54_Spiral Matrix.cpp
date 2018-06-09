// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
54. Spiral Matrix
https://leetcode-cn.com/problems/spiral-matrix/description/

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.
*/

/*整体思路是 :	可以设置一个上下界，每次按四个方向遍历，目前还不是这种方式，
但复杂度没有区别。
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0)
			return result;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int x = min(rows, cols);
		if (rows == 1 || cols == 1) {
			if (rows == 1) {
				for (int i = 0; i < cols; ++i)
					result.push_back(matrix[0][i]);
			}
			else {
				for (int i = 0; i < rows; ++i)
					result.push_back(matrix[i][0]);
			}
			return result;
		}
		for (int i = 0; i < x / 2; ++i) {
			for (int j = i; j < cols - i - 1; ++j)
				result.push_back(matrix[i][j]);
			for (int j = i; j < rows - i - 1; ++j)
				result.push_back(matrix[j][cols - i - 1]);
			for (int j = cols - i - 1; j > i; --j)
				result.push_back(matrix[rows - i - 1][j]);
			for (int j = rows - i - 1; j > i; --j)
				result.push_back(matrix[j][i]);
		}
		if (x % 2) {
			if ((rows % 2 == 0 && cols % 2 == 0) || rows == 2 || cols == 2)
				return result;
			if (rows < cols) {
				for (int i = x / 2; i <= cols - x / 2 - 1; ++i)
					result.push_back(matrix[x / 2][i]);
				return result;
			}
			for (int i = x / 2; i <= rows - x / 2 - 1; ++i)
				result.push_back(matrix[i][x / 2]);
			return result;
		}
		return result;
	}
};