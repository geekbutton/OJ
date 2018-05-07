// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
561. 数组拆分

https://leetcode-cn.com/problems/array-partition-i/description/
*/


class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int result = 0;
		for (int i = 0; i < nums.size(); i += 2) {
			result += nums[i];
		}
		return result;
	}
};