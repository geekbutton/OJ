// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
239. �����������ֵ

https://leetcode-cn.com/problems/sliding-window-maximum/description/

����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ
��ֻ���Կ����ڻ������� k �ڵ����֡���������ÿ��ֻ�����ƶ�һλ��
���ػ����������ֵ��
����Լ��� k ������Ч�ģ�1 �� k �� ��������Ĵ�С�����������鲻Ϊ�ա�
*/

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> im;
		for (auto x : words)
			++im[x];
		priority_queue<pair<int, string>> iq;
		for (auto iter = im.begin(); iter != im.end(); ++iter)
			iq.push(pair<int, string>(iter->second, iter->first));

		int flag = iq.top().first;
		set<string> ss;
		vector<string> result;
		int temp_k;
		while (k > 0) {
			temp_k = k;
			int value = iq.top().first;
			if (flag != value){
				flag = value;
				result.insert(result.end(), ss.begin(), ss.end());
				ss.clear();
				ss.insert(iq.top().second);
				iq.pop();
				--k;
				continue;
			}
			int count = 1;
			while (flag==value) {
				ss.insert(iq.top().second);
				iq.pop();
				value = iq.top().first;
				++count;
			}
			k -= count;
		}
		auto iter = ss.begin();
		while (temp_k--) {
			result.insert(result.end(), *iter);
			++iter;

		}
		return result;
	}
};
