// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
48. 旋转图像

https://leetcode-cn.com/problems/rotate-image/description/
*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int iterations = matrix.size()/2;
		int n = matrix.size();

		for (int i = 0; i < iterations; ++i) {
			int temp_value = matrix[i][i];
			for (int j = i; j < n - i - 1; ++j) {
				temp_value = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = temp_value;
 
			}
		}
	}
};