// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
47. 全排列 II
https://leetcode-cn.com/problems/permutations-ii/description/

给定一个可包含重复数字的序列，返回所有不重复的全排列。
*/

/*整体思路是 :	这道题非常重要也非常经典，其包括两种经典的算法实现：递归实现与非递归实现。解法
跟46题基本一致。对于递归实现这里采用了一个无序map用于判断是否存在重复元素的交换。对于非递归实现，
思路就是首先获得数字的最小排列情况，然后不断求其下一个排列(解法见习题31)，直到最大排列。
注意，这道题的非递归实现对有重复数字的序列和无重复序列的都是一样的，无需修改。
*/
//递归实现
void Permutation(vector<int>, vector<vector<int>>&, vector<int>);
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() == 0)
			return result;
		vector<int> value;
		Permutation(nums, result, value);
		return result;
	}
};

void Permutation(vector<int> nums, vector<vector<int>>& result, vector<int> value) {
	if (nums.size() == 1) {
		value.push_back(nums[0]);
		result.push_back(value);
		return;
	}
	unordered_map<int, int> im;		//设置一个无序map用于记录已经和哪些元素发生过交换
	for (int i = 0; i < nums.size(); ++i) {
		//交换当前vector的第一个元素从第一个元素开始的所有元素逐一交换
		if (i != 0 && nums[0] == nums[i])
			continue;
		if (im.size() && im[nums[i]]==1)	//若检查到nums[i]对应元素在map中，则不需要再重复处理
			continue;
		im[nums[i]] = 1;
		swap(nums[0], nums[i]);
		value.push_back(nums[0]);
		vector<int> temp(nums.begin() + 1, nums.end());
		Permutation(temp, result, value);
		value.pop_back();		//注意返回后删除前次交换的结果
		swap(nums[0], nums[i]);
	}
}
//非递归实现(对于元素有无重复都可以顺利解决)
bool next_permutation(vector<int>&);
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());		//首先排序
		result.push_back(nums);
		while (next_permutation(nums)) {
			result.push_back(nums);
		}
		return result;
	}
};
//对每一个排列求其下一个排列，直到最大排列
bool next_permutation(vector<int>& nums) {
	int num = nums.size();
	for (int i = num - 1; i > 0; --i) {
		if (nums[i] <= nums[i - 1])
			continue;
		int j = i;
		int min_index = j;
		for (; j < num; ++j) {
			if (nums[j] <= nums[i - 1])
				continue;
			if (nums[j] < nums[min_index])
				min_index = j;
		}
		swap(nums[i - 1], nums[min_index]);
		sort(nums.begin() + i, nums.end());
		return true;
	}
	return false;
}