// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
73. 矩阵置零
https://leetcode-cn.com/problems/set-matrix-zeroes/description/

给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。
请使用原地算法。
*/

/*整体思路是 :	遍历元素，当元素为0时，置其所在行和列的首元素为0。
注意对matrix[0][0]元素的处理，因为其既代表行首元素也代表列首元素，所以为了区分
设置两个额外的标志量flag_c，flag_r表示第一列，第一行是否需要置0。
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int flag_r = 0, flag_c = 0;			//处理第一行和第一列的标志
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if ((i && j) && matrix[i][0] == 0 && matrix[0][j] == 0)
					continue;
				//元素为0，则对应行列首元素置0，或flag_c，flag_r置0
				if (matrix[i][j] == 0) {
					if (i && j) {
						matrix[i][0] = 0;
						matrix[0][j] = 0;
						continue;
					}
				    if (!i && !flag_r) {
						flag_r = 1;
					}
				    if (!j && !flag_c)
						flag_c = 1;
				}
			}
		}
		//根据各行各列首元素是否为0判断该行列是否需要全部置0
		for (int i = 1; i < rows; ++i) {
			if (!matrix[i][0]) {
				for (int j = 1; j < cols; ++j)
					matrix[i][j] = 0;
			}
		}
		for (int i = 1; i < cols; ++i) {
			if (!matrix[0][i]) {
				for (int j = 1; j < rows; ++j)
					matrix[j][i] = 0;
			}
		}
		if (flag_r) {
			for (int i = 0; i < cols; ++i)
				matrix[0][i] = 0;
		}
		if (flag_c) {
			for (int i = 0; i < rows; ++i)
				matrix[i][0] = 0;
		}
	}
};
