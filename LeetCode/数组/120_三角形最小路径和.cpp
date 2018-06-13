// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
120. 三角形最小路径和
https://leetcode-cn.com/problems/triangle/description/

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/

/*整体思路是 :	本质上就是杨辉三角+动态规划，杨辉三角的元素产生方法即为本题中的相邻路径。
由于算法要求使用O(n)的额外空间，所以对于动态规划只保留前次结果和当次结果而非产生一个
n*n的数组用于保存结果。
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> result;
		int rows = triangle.size();
		if (!rows)
			return 0;
		result.push_back(triangle[0][0]);
		for (int i = 1; i < rows; ++i) {
			vector<int> temp = triangle[i];
			//每一行头尾元素只能由上一行的头元素(尾元素)到达
			//中间元素则可通过杨辉三角的方式得到两个不同的路径，选择较短的路径
			vector<int> iv{ result[0] + temp[0] };
			for (int j = 1; j < i + 1; ++j) {
				if (j == i) {
					iv.push_back(result[result.size() - 1] + temp[j]);
					result = iv;
					break;
				}
				else {
					iv.push_back((result[j - 1] <= result[j] ? result[j - 1] : result[j]) + temp[j]);
					continue;
				}
			}
		}
		//最后遍历最后一行的所有点的对应路径，找到最短路径
		int minPath = result[0];
		for (auto x : result) {
			if (x < minPath)
				minPath = x;
		}
		return minPath;
	}
};