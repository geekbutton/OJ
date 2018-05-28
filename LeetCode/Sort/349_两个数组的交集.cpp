// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
349. ��������Ľ���
https://leetcode-cn.com/problems/intersection-of-two-arrays/description/

�����������飬дһ���������������ǵĽ�����
*/

/*��Ҫ˼·���ֽ������������������αȽϡ�
ʱ�临�ӶȽϸ�
*/
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> temp_result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
			if (nums1[i] < nums2[j])
				++i;
			else if (nums1[i] > nums2[j])
				++j;
			else if (nums1[i] == nums2[j]) {
				temp_result.insert(nums1[i]);
				++i; ++j;
			}
		}
		vector<int> result(temp_result.begin(), temp_result.end());

		return result;
	}
};