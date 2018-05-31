// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
26. ɾ�����������е��ظ���
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/

����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�
ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
*/

/*����˼·�� :	��������ָ��ֱ�ָ������ͷ�ͺ�һ��Ԫ�أ����ν��бȽ�
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if ((int)nums.size() == 0 || (int)nums.size() == 1)
			return nums.size();
		int i = 0;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[i] == nums[j]) {
				continue;
			}
			nums[++i] = nums[j];
		}
		return ++i;
	}
};