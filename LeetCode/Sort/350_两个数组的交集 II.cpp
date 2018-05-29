// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
350. ��������Ľ��� II
https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/

�����������飬дһ���������������ǵĽ�����
��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
����:
	��������������Ѿ��ź����أ��㽫����Ż�����㷨��
	��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
	���nums2��Ԫ�ش洢�ڴ����ϣ��ڴ������޵ģ��㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿
*/

/*����˼·�����ַ�����
	1.	��������forѭ�������Ƚϣ�ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
	2.	�ȶ�������������������һ��forѭ��������ʱ�临�Ӷ�O(nlog(n))���ռ临�Ӷ�O(1)
	3.	�Խ�С�������齨����ϣ���Խϴ󳤶����������ڹ�ϣ���в��ң�ʱ�临�Ӷ�O(1)���ռ临�Ӷ�
		O(min(n))(�÷����ǳ����������������С���ϴ�������)
*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1 , vector<int>& nums2) {
		vector<int> result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		for (; i < nums1.size() && j < nums2.size();) {
			//ע���жϻ��ֵ�����������������ֵ�ô�Сȷ���ĸ�����ǰ��
			if (nums1[i] < nums2[j]) {
				++i;
				continue;
			}
			else if (nums1[i] > nums2[j]) {
				++j;
				continue;
			}
			result.push_back(nums1[i]);
			++i;
			++j;
		}
		return result;
	}
};