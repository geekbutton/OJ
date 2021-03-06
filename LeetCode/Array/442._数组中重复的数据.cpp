// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
442. 数组中重复的数据

https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
*/

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[abs(nums[i]) - 1] < 0)
				result.push_back(abs(nums[i]));
			nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
		}
		return result;
	}
};