// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
53. 最大子序和
https://leetcode-cn.com/problems/maximum-subarray/description/

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组
最少包含一个元素），返回其最大和。
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

/*整体思路是 :	先找到第一个大于0的数，开始计算和（在找的过程中，保持更新当前最大值）
当要加的数大于0，则直接相加并比较更新最大值。如小于0，判断加之后和是否大于0，若是则相加，
否则和置0，重新开始求解子数组。注意过程中最大值一直在更新。该算法复杂度为O(n)。
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int i = 0, max = nums[0];
		for (; i < nums.size(); ++i) {
			if (nums[i] <= 0) {
				if (nums[i] > max)
					max = nums[i];
				continue;
			}
			break;
		}
		int sum = 0;
		for (i; i < nums.size(); ++i) {
			if (nums[i] >= 0) {
				sum += nums[i];
				if (sum > max)
					max = sum;
				continue;
			}
			sum = (sum + nums[i]) > 0 ? (sum + nums[i]) : 0;
			
		}
		return max;
	}
};