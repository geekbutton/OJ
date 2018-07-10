// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
77. 组合
https://leetcode-cn.com/problems/combinations/description/

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
*/

/*整体思路是 :	因为这道题的组合都是按顺序排列的，及从1到n，因此
依旧是采用深度优先回溯算法，遍历所有可能的组合。
*/
void Combine(int, int, int, int, vector<int>, vector<vector<int>>&);
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		if (n == 0 || k == 0)
			return result;
		vector<int> value;
		Combine(1, k, n, 0, value, result);
		return result;
	}
};

void Combine(int level, int k, int n, int l, vector<int>value, vector<vector<int>>& result) {
	for (int i = l + 1; i <= n - k + level; ++i) {	//n-k-level表示的是当前能够取到的最大数
		value.push_back(i);
		if (level == k) {
			result.push_back(value);
		}
		else {//注意这里，后一层能取到的数最小从当前层取的数的下一个开始而非从1开始
			Combine(level + 1, k, n, i, value, result);
		}
		value.pop_back();
	}
}