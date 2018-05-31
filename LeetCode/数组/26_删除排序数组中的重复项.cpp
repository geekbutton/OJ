// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
26. 删除排序数组中的重复项
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/

给定一个排序数组，你需要在原地删除重复出现的元素，
使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

/*整体思路是 :	利用两个指针分别指向数组头和和一个元素，依次进行比较
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if ((int)nums.size() == 0 || (int)nums.size() == 1)
			return nums.size();
		int i = 0;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[i] == nums[j]) {
				continue;
			}
			nums[++i] = nums[j];
		}
		return ++i;
	}
};