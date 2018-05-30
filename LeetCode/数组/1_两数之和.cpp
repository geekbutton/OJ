// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
1. ����֮��
https://leetcode-cn.com/problems/two-sum/description/


����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������

����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�
*/

/*����˼·�� :	���ù�ϣ��ʵ��O(n)���ӶȵĲ��ң��ҽ�����һ�Ρ�
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_multimap<int, int> im;
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = im.find(target - nums[i]);
			if (iter != im.end()) {
				result.insert(result.end(), { iter->second,i });;
				return result;
			}
			im.insert(pair<int, int>(nums[i], i));
		}
	}
};