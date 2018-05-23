// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
692. 前K个高频单词

https://leetcode-cn.com/problems/top-k-frequent-words/description/

给一非空的单词列表，返回前 k 个出现次数最多的单词。
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
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
