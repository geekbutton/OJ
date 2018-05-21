// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
451. 根据字符出现频率排序

https://leetcode-cn.com/problems/sort-characters-by-frequency/description/

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
*/

/*注意时间复杂度带来的问题，应该使用哈希表加堆的组合，对应的是采用哈希表为底层实现的
unordered_map
*/
class Solution {
public:
	string frequencySort(string s) {
		if (s.size() == 0)
			return s;
		unordered_map<char, int> ism;
		priority_queue<pair<int, char>> iq;
		for (auto ch : s)
			++(ism[ch]);
		for (auto iter : ism)
			iq.push({ iter.second,iter.first });		//注意这里堆中的map两个值交换了顺序
		for (int i = 0; i < s.size(); i) {
			int frequency = iq.top().first;
			char value = iq.top().second;
			while (frequency--)
				s[i++] = value;
			iq.pop();
		}
		return s;
	}
};
