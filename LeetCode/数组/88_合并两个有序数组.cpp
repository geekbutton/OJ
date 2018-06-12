// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
88. 合并两个有序数组
https://leetcode-cn.com/problems/merge-sorted-array/description/

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
	初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
	你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/

/*整体思路是 :	可以新定义一个可以容纳m+n的数组，然后从两个有序数组头开始遍历比较，
将元素逐个插入新数组中，最后再赋值回nums1。但是该算法需要O(m+n)的空间复杂度，因此考虑O(1)的
空间复杂度，可以从两个数组的最后反序插入元素。
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = nums1.size() - 1;
		//反序插入元素，每次插入较大的元素
		for (--m, --n; m >= 0 && n >= 0;) {
			nums1[index--] = (nums1[m] > nums2[n]) ? (nums1[m--]) : (nums2[n--]);
		}
		while (m >= 0) {
			nums1[index--] = nums1[m--];
		}
		while (n >= 0)
			nums1[index--] = nums2[n--];
		return;
	}
};