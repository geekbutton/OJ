// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
35. 搜索插入位置
https://leetcode-cn.com/problems/search-insert-position/description/

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
*/

/*整体思路是 :	按照二分查找先找到第一个等于目标值的位置，关键是当没有找到时的处理。
如没有找到对应元素，则在最后一次迭代，即l>=r的情况时进行判断，如果target大于此时唯一的值
nums[l]，则返回索引为l+1，否则为l。
*/
int find_index(int, int, vector<int>&, int);
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		int index = 0;
		index = find_index(0, nums.size() - 1, nums, target);
		return index;
	}
};

int find_index(int l, int r, vector<int>&nums, int target) {
	//注意判断条件，当只有两个元素并进入下一次左递归时，有可能出现l>r的情况
	if (l >= r && nums[l] != target) {
		if (target > nums[l])
			return l + 1;		//大于则插入在l+1位置
		return l;				//小于则插入在l位置
	}
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return mid;
	if (target > nums[mid])
		return find_index(mid + 1, r, nums, target);
	return find_index(l, mid - 1, nums, target);
}