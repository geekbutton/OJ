// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
46. 全排列
https://leetcode-cn.com/problems/permutations/description/

给定一个没有重复数字的序列，返回其所有可能的全排列。
*/

/*整体思路是 :	这道题非常重要也非常经典，其包括两种经典的算法实现：递归实现与非递归实现。
对于递归实现，思路就是从第一个数字其每个数字与后面的数字交换。对于非递归实现，思路就是首先获得
数字的最小排列情况，然后不断求其下一个排列(解法见习题31)，直到最大排列。
*/
//递归实现
void Permutation(vector<int>, vector<vector<int>>&, vector<int>);
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
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
	for (int i = 0; i < nums.size(); ++i) {
		//交换当前vector的第一个元素从第一个元素开始的所有元素逐一交换
		swap(nums[0], nums[i]);
		value.push_back(nums[0]);
		vector<int> temp(nums.begin() + 1, nums.end());
		Permutation(temp, result, value);
		value.pop_back();		//注意返回后删除前次交换的结果
		swap(nums[0], nums[i]);
	}
}
//非递归实现
bool next_permutation(vector<int>&);
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
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
		if (nums[i] < nums[i - 1])
			continue;
		int j = i;
		int min_index = j;
		for (; j < num; ++j) {
			if (nums[j] < nums[i - 1])
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