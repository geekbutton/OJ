// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
45. 跳跃游戏 II
https://leetcode-cn.com/problems/jump-game-ii/description/

给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
*/

/*整体思路是 :	利用贪婪算法，每次选择的是下一步能达到的地方最远的点。
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int count = 0;
		int current = 0, l = 0, num = nums.size();
		for (current; current < num - 1;) {
			int value = nums[current];
			int max_index = current + 1;				//最远的点的索引
			if (current + nums[current] >= num - 1)
				return ++count;
			for (l = current + 1; l <= current + value; ++l) {
				//找出下一步能达到最远地方的点
				if (nums[l] + l >= nums[max_index] + max_index) {
					max_index = l;
				}
			}
			++count;
			current = max_index;
		}
		return count;
	}
};