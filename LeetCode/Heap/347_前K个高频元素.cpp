// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
347. ǰK����ƵԪ��

https://leetcode-cn.com/problems/top-k-frequent-elements/description/

����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
����㷨��ʱ�临�Ӷȱ������� O(n log n) , n ������Ĵ�С��
*/

/*��Ҫ˼·�����ö�������ǰK������Ԫ�أ�ע��Ӧʹ������map�Ա�֤ʱ�临�Ӷ�
*/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> result;
		unordered_map<int, int> im;
		for (auto v : nums)
			++im[v];
		priority_queue<pair<int, int>> iq;
		for (auto iter : im)
			iq.push({ iter.second,iter.first });		//ע��Ѷ�ӦmapԪ�ؽ���
		int n = 0;
		while (n != k) {
			result.push_back(iq.top().second);
			iq.pop();
			++n;
		}
		return result;
	}
};
