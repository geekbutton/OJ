// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
55. Jump Game
https://leetcode-cn.com/problems/spiral-matrix/description/

Given an array of non-negative integers, 
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/

/*整体思路是 :	类似之前45求最短跳的问题，都是利用贪婪算法找出下一步能走到的最远的点，
然后通过判断这些最远的点能否到达终点来确定是否能走到终点，注意0值的处理。
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i = 0, max_index = 0;
		int num = nums.size();
		if (nums[0] >= num - 1)
			return true;
		for (i; i < num;) {
			for (int j = i + 1; j <= nums[i] + i; ++j) {
				if (j + nums[j] >= num - 1)
					return true;
				if (j + nums[j] >= max_index + nums[max_index])
					max_index = j;
			}
			if (nums[i] == 0)
				return false;
			i = max_index;
		}
		return false;
	}
};