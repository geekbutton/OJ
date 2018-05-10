// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
485. �������1�ĸ���

https://leetcode-cn.com/problems/max-consecutive-ones/description/
*/

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max_result = 0;
		int num = nums.size();
		for (int i = 0; i < num; ++i) {
			if (nums[i] == 1) {
				int temp_result = 1;
				for (int j = i + 1; j < num; ++j) {
					if (nums[j] == 1)
						++temp_result;
					else {
						i = j;
						break;
					}
				}
				if (temp_result > max_result)
					max_result = temp_result;
			}
		}
		return max_result;
	}
};

