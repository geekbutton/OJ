// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
31. 下一个排列
https://leetcode-cn.com/problems/next-permutation/description/

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
*/

/*整体思路是 :	从最后一个元素向前找，找到第一个nums[i-1]<nums[i]的位置，然后在[i,n-1]
范围内找到比nums[i-1]大的最小的元素与其交换，交换完成后对[i,n-1]范围内的数值按递增序重新
排列，以保证后半段是最小的情况。
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int num = nums.size();
		for (int i = num - 1; i > 0; --i) {
			if (nums[i - 1] >= nums[i])
				continue;
			int temp_min = i;
			for (int j = i; j < num; ++j) {
				//找到后半段比nums[i]大的最小的数
				if (nums[j] > nums[i - 1])
					temp_min = (nums[temp_min] < nums[j] ? temp_min : j);
			}
			//交换两个元素，重排后半段元素为最小顺序
			swap(nums[i - 1], nums[temp_min]);
			sort(nums.begin() + i, nums.end());
			return;
		}
		//如果for循环遍历了所有元素，则说明整个序列为递减序排列，则重排其为递增序即可
		//得到对应的最小排列
		sort(nums.begin(), nums.end());
	}
};