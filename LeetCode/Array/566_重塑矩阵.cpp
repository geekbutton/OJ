// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
566. 重塑矩阵

https://leetcode-cn.com/problems/reshape-the-matrix/description/
*/

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int rows = nums.size();
		int cols = nums[0].size();

		if ((r*c != rows*cols) || (rows == r && cols == c))
			return nums;

		vector<vector<int>> result(r,vector<int>());
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				int row_index = (i*cols + j) / c;
				result[row_index].push_back(nums[i][j]);
			}
		}
		return result;
	}
};

