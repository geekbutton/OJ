// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
75. 分类颜色
https://leetcode-cn.com/problems/sort-colors/description/

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

进阶：
	一个直观的解决方案是使用计数排序的两趟扫描算法。
	首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
	你能想出一个仅使用常数空间的一趟扫描算法吗？
*/

/*主要思路是遍历一遍数组，将小于1的元素从最前面开始放，把大于1的数从最后开始放
*/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, i = 0, right = nums.size() - 1;		//初始交换的位置
		while (i < nums.size()) {
			if (nums[i] < 1) {
				swap(nums[i], nums[left]);
				++left;
				++i;							//小数往前交换可以增加i，因此原位置的元素必定不大于1
			}
			else if (nums[i] > 1 && i < right) {		//注意i应该小于right索引，否则会把2向当前位置之前的位置移动
				swap(nums[i], nums[right]);
				--right;						//大数往后交换时不能增加i，因为不知道交换后的数据的值
			}
			else
				++i;
		}
	}
};