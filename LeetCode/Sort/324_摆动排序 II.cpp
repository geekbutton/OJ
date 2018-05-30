// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
324. 摆动排序 II
https://leetcode-cn.com/problems/wiggle-sort-ii/description/

给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
你能用 O(n) 时间复杂度和/或原地 O(1) 额外空间来实现吗？
*/

/*整体思路是 :	先将所有元素排序，然后将整个数组分为前半部分和后半部分(注意元素总数为
奇数时，前半部分多一个元素)，然后从两个部分的最后一个元素开始取值组合到一起开始组成新的
数组(注意是从后往前，如果从前往后则部分情况不能正确处理)。
该种方法不满足时间复杂度与空间复杂度的要求
*/
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1, mid = (left + right) / 2 + 1;
		int count = min(mid, (int)nums.size() - mid);
		vector<int> result = nums;
		int index = 0;
		mid--;
		while (count--) {
			nums[index++] = result[mid--];
			nums[index++] = result[right--];
		}
		if (nums.size() % 2) {
			nums[index] = result[mid];
		}
	}
};