// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
1. 两数之和
https://leetcode-cn.com/problems/two-sum/description/


给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
*/

/*整体思路是 :	利用哈希表实现O(n)复杂度的查找，且仅遍历一次。
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_multimap<int, int> im;
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = im.find(target - nums[i]);
			if (iter != im.end()) {
				result.insert(result.end(), { iter->second,i });;
				return result;
			}
			im.insert(pair<int, int>(nums[i], i));
		}
	}
};