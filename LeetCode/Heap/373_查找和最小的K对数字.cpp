// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
373. ���Һ���С��K������

https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/description/

�����������������е��������� nums1 �� nums2, �Լ�һ������ k��
����һ��ֵ (u,v)�����е�һ��Ԫ������ nums1���ڶ���Ԫ������ nums2��
�ҵ�����С�� k ������ (u1,v1), (u2,v2) ... (uk,vk)��
*/

/*����˼·�ǣ�����һ�����ȶѽ�Ԫ����˳�����������������������ǰK����
ע���Զ���comp����
*/
class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		
		
		auto comp = [](pair<int, int> a, pair<int, int> b) {		//lambda����
			return (a.first + a.second) > (b.first + b.second);
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> iq(comp);	//ע������д��
		for (int i = 0; i < min((int)nums1.size(), k); ++i) {		//����min����������
			for (int j = 0; j < min((int)nums2.size(), k); ++j) {
				iq.push(pair<int, int>(nums1[i], nums2[j]));
			}
		}
		vector<pair<int, int>> result;
		k = min(nums1.size()*nums2.size(), k);
		while (k--) {
			result.push_back(iq.top());
			iq.pop();
		}
		return result;
	}
};