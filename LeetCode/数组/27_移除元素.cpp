// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
27. 移除元素
https://leetcode-cn.com/problems/remove-element/description/

给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

/*整体思路是 :	利用两个指针分别指向数组头和和一个元素，依次进行比较
*/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;
		int i = 0;
		for (int j = 0; j < nums.size(); ++j) {
			if (nums[j] != val) {
				nums[i] = nums[j];
				++i;
			}
		}
		return ++i;
	}
};