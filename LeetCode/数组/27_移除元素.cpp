// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
27. �Ƴ�Ԫ��
https://leetcode-cn.com/problems/remove-element/description/

����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/

/*����˼·�� :	��������ָ��ֱ�ָ������ͷ�ͺ�һ��Ԫ�أ����ν��бȽ�
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