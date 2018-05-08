// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
64. 最小路径和(动态规划的思路)

https://leetcode-cn.com/problems/minimum-path-sum/description/
*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();
		int min_ps = 0;
		vector<int> current_result;
		vector<int> prev_result;
		for (int i = 0; i < cols; ++i) {
			min_ps += grid[0][i];
			prev_result.push_back(min_ps);
		}

		for (int i = 1; i < rows; ++i) {
			current_result.push_back(prev_result[0] + grid[i][0]);
			for (int j = 1; j < cols; ++j) {
				int temp_value = (prev_result[j] + grid[i][j]			\\
					<= current_result[current_result.size() - 1] + grid[i][j]) ? \\
					prev_result[j] + grid[i][j]:current_result[current_result.size() - 1] + grid[i][j];
				current_result.push_back(temp_value);
			}
			prev_result = current_result;
			current_result.clear();
		}

		return prev_result[cols - 1];
	}
};