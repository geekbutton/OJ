// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
324. �ڶ����� II
https://leetcode-cn.com/problems/wiggle-sort-ii/description/

����һ����������� nums�������������г� nums[0] < nums[1] > nums[2] < nums[3]... ��˳��
������ O(n) ʱ�临�ӶȺ�/��ԭ�� O(1) ����ռ���ʵ����
*/

/*����˼·�� :	�Ƚ�����Ԫ������Ȼ�����������Ϊǰ�벿�ֺͺ�벿��(ע��Ԫ������Ϊ
����ʱ��ǰ�벿�ֶ�һ��Ԫ��)��Ȼ����������ֵ����һ��Ԫ�ؿ�ʼȡֵ��ϵ�һ��ʼ����µ�
����(ע���ǴӺ���ǰ�������ǰ�����򲿷����������ȷ����)��
���ַ���������ʱ�临�Ӷ���ռ临�Ӷȵ�Ҫ��
*/
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1, mid = (left + right) / 2 + 1;
		int count = min(mid, (int)nums.size() - mid);
		vector<int> result = nums;
		int index = 0;
		mid--;
		while (count--) {
			nums[index++] = result[mid--];
			nums[index++] = result[right--];
		}
		if (nums.size() % 2) {
			nums[index] = result[mid];
		}
	}
};