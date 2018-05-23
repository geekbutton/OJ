// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
692. ǰK����Ƶ����

https://leetcode-cn.com/problems/top-k-frequent-words/description/

��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������
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
				continue;
			}
			int count = 1;
			while (flag==value && iq.size()!=0) {
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
