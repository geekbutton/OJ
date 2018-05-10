// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
59. 螺旋矩阵 II

https://leetcode-cn.com/problems/spiral-matrix-ii/description/
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n,vector<int>(n,0));
		int iterations = n / 2;
		int num = 1;
		for (int i = 0; i < iterations; ++i) {
			//按照正方形来处理，且四个面每个面假设边长为n，
			//则处理n-1个数以避免重复设置正方形的四个顶点
			for (int j = i; j < n - i - 1; ++j)
				result[i][j] = num++;
			for (int j = i; j < n - i - 1; ++j)
				result[j][n - i - 1] = num++;
			for (int j = n - i - 1; j > i; --j)
				result[n - 1 - i][j] = num++;
			for (int j = n - 1 - i; j > i; --j)
				result[j][i] = num++;
		}
		if (n % 2 == 1)						//处理当n为奇数时数组中心的那个值
			result[iterations][iterations] = num;
		return result;
	}
};

