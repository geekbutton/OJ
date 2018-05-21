// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
215. 数组中的第K个最大元素

https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/

在未排序的数组中找到第 k 个最大的元素。请注意，
你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/

/*主要思路：利用堆排序获得第K个最大的元素
*/
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> iq;
		for (auto iter : nums) {
			iq.push(iter);
		}
		int n = 1;
		while (n != k) {
			iq.pop();
			++n;
		}
		return iq.top();
	}
};
