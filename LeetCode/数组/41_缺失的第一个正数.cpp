// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
41. 缺失的第一个正数
https://leetcode-cn.com/problems/first-missing-positive/description/

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/

/*整体思路是 :	由题意可得，未出现的最小正整数应该在范围[1，n+1]之间，因此对数组中的所有元素
重新放置，当检测到0<n[i]<n+1时,将其与位置n[i]处的元素交换(如元素1与n[0]交换，使其位于n[0]处)(负值和超过范围的不交换，交换位置值
等于该位置索引加1的，不交换)，完成后重新遍历数组，第一个值不对应的元素即为缺失的最小正整数。
需要注意的是索引+1等于该索引处应该放置的值。
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0)
			return 1;
		int result = 0;
		for (int i = 0; i < nums.size(); ++i) {
			//如果所引出的值已经对应了，就无需交换，直接处理下一个
			if (nums[i] == i + 1)
				continue;
			//注意这里的判断条件，只处理在1-n范围的元素，且不交换以正确存放的位置的数据
			if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] -1] != nums[i]) {
				swap(nums[nums[i] - 1], nums[i]);
				--i;
			}
		}
		int i = 0;
		for (i; i < nums.size(); ++i) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return i + 1;
	}
};