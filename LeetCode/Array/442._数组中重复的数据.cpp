// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
442. �������ظ�������

https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
*/

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i) {
			int index = abs(nums[i]) - 1;
			if (nums[index] < 0)
				result.push_back(index + 1);
			nums[index] = -nums[index];
		}
		return result;
	}
};