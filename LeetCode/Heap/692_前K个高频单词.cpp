// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
239. 滑动窗口最大值

https://leetcode-cn.com/problems/sliding-window-maximum/description/

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。
返回滑动窗口最大值。
你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。
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
