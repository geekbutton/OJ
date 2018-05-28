// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
349. 两个数组的交集
https://leetcode-cn.com/problems/intersection-of-two-arrays/description/

给定两个数组，写一个函数来计算它们的交集。
*/

/*主要思路是现将两个数组排序，再依次比较。
时间复杂度较高
*/
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> temp_result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
			if (nums1[i] < nums2[j])
				++i;
			else if (nums1[i] > nums2[j])
				++j;
			else if (nums1[i] == nums2[j]) {
				temp_result.insert(nums1[i]);
				++i; ++j;
			}
		}
		vector<int> result(temp_result.begin(), temp_result.end());

		return result;
	}
};