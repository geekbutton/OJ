// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
766. 托普利茨矩阵

https://leetcode-cn.com/problems/toeplitz-matrix/description/
*/

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();

		for (int i = 0; i < rows - 1; ++i){
			for (int j = 0; j < cols - 1; ++j) {
				if (matrix[i][j] != matrix[i + 1][j + 1])
					return false;
			}
		}
		return true;
	}
};