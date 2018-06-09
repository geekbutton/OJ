// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
63. 不同路径 II
https://leetcode-cn.com/problems/unique-paths-ii/description/

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
*/

/*整体思路是 :	同62题动态规划思路，增加了对障碍物置0的处理。
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int rows = obstacleGrid.size();
		int cols = obstacleGrid[0].size();
		vector<vector<int>> iv(rows ,vector<int>(cols,0) );
		if (!obstacleGrid[0][0])
			iv[0][0] = 1;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (!obstacleGrid[i][j]) {
					if (i == 0 && j == 0)
						continue;
					if (i == 0) {
						iv[i][j] = iv[i][j - 1];
					}
					else if (j == 0)
						iv[i][j] = iv[i - 1][j];
					else
						iv[i][j] = iv[i][j - 1] + iv[i - 1][j];
				}
			}
		}
		return iv[rows - 1][cols - 1];
	}
};
