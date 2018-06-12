// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
88. �ϲ�������������
https://leetcode-cn.com/problems/merge-sorted-array/description/

�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
˵��:
	��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
	����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
*/

/*����˼·�� :	�����¶���һ����������m+n�����飬Ȼ���������������ͷ��ʼ�����Ƚϣ�
��Ԫ����������������У�����ٸ�ֵ��nums1�����Ǹ��㷨��ҪO(m+n)�Ŀռ临�Ӷȣ���˿���O(1)��
�ռ临�Ӷȣ����Դ������������������Ԫ�ء�
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = nums1.size() - 1;
		//�������Ԫ�أ�ÿ�β���ϴ��Ԫ��
		for (--m, --n; m >= 0 && n >= 0;) {
			nums1[index--] = (nums1[m] > nums2[n]) ? (nums1[m--]) : (nums2[n--]);
		}
		while (m >= 0) {
			nums1[index--] = nums1[m--];
		}
		while (n >= 0)
			nums1[index--] = nums2[n--];
		return;
	}
};