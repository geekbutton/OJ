// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
31. ��һ������
https://leetcode-cn.com/problems/next-permutation/description/

ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�
�����������һ����������У��������������г���С�����У����������У���
����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣
*/

/*����˼·�� :	�����һ��Ԫ����ǰ�ң��ҵ���һ��nums[i-1]<nums[i]��λ�ã�Ȼ����[i,n-1]
��Χ���ҵ���nums[i-1]�����С��Ԫ�����佻����������ɺ��[i,n-1]��Χ�ڵ���ֵ������������
���У��Ա�֤��������С�������
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int num = nums.size();
		for (int i = num - 1; i > 0; --i) {
			if (nums[i - 1] >= nums[i])
				continue;
			int temp_min = i;
			for (int j = i; j < num; ++j) {
				//�ҵ����α�nums[i]�����С����
				if (nums[j] > nums[i - 1])
					temp_min = (nums[temp_min] < nums[j] ? temp_min : j);
			}
			//��������Ԫ�أ����ź���Ԫ��Ϊ��С˳��
			swap(nums[i - 1], nums[temp_min]);
			sort(nums.begin() + i, nums.end());
			return;
		}
		//���forѭ������������Ԫ�أ���˵����������Ϊ�ݼ������У���������Ϊ�����򼴿�
		//�õ���Ӧ����С����
		sort(nums.begin(), nums.end());
	}
};