// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
118. 杨辉三角
https://leetcode-cn.com/problems/pascals-triangle/description/

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
*/

/*整体思路是 :	没什么好说的，按杨辉三角求法逐行求。
*/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0) {
			return vector<vector<int>>();
		}
		vector<vector<int>> result{ vector<int>{1} };
		for (int i = 1; i < numRows; ++i) {
			vector<int> iv{ 1 };
			int num = i + 1;
			for (int j = 1; j < num; ++j) {
				if (j == i) {
					iv.push_back(1);
					result.push_back(iv);
					break;
				}
				else {
					iv.push_back((result[i - 1][j - 1] + result[i - 1][j]));
					continue;
				}
			}
		}
		return result;
	}
};