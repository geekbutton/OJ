// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
84. 柱状图中最大的矩形
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

/*整体思路是 :	利用栈来处理以实现O(n)复杂度的解法。生成一个递增栈，当元素大于等于栈顶元素
时直接推入栈中，当小于时，则从栈中弹出元素计算对应面积，知道栈顶元素小于当前元素
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int num = heights.size();
		int result = heights[0], index_0 = 0;
		stack<int> is;
		is.push(0);
		for (int i = 1; i < num; ++i) {
			if (is.empty() || heights[i] >= heights[is.top()]) {
				is.push(i);
				continue;
			}
			while (!is.empty() && heights[is.top()] > heights[i]) {
				int index = is.top();
				int value = heights[index];
				is.pop();
				//关键是这个计算面积的公式，区分栈中的最后一个元素和非最后一个元素
				result = max(result, value*(is.empty() ? i : (i - 1 - is.top())));
			}
			is.push(i);
		}
		heights.pop_back();
		return result;
	}
};