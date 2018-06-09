// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
55. Jump Game
https://leetcode-cn.com/problems/spiral-matrix/description/

Given an array of non-negative integers, 
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/

/*����˼·�� :	����֮ǰ45������������⣬��������̰���㷨�ҳ���һ�����ߵ�����Զ�ĵ㣬
Ȼ��ͨ���ж���Щ��Զ�ĵ��ܷ񵽴��յ���ȷ���Ƿ����ߵ��յ㣬ע��0ֵ�Ĵ���
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i = 0, max_index = 0;
		int num = nums.size();
		if (nums[0] >= num - 1)
			return true;
		for (i; i < num;) {
			for (int j = i + 1; j <= nums[i] + i; ++j) {
				if (j + nums[j] >= num - 1)
					return true;
				if (j + nums[j] >= max_index + nums[max_index])
					max_index = j;
			}
			if (nums[i] == 0)
				return false;
			i = max_index;
		}
		return false;
	}
};