// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
49. 字母异位词分组
https://leetcode-cn.com/problems/group-anagrams/description/

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*/

/*整体思路是 :	利用哈希表进行处理。首先对每个元素进行排序，从而使得字母异位词对应相同的结果，
将排序后的结果作为key，排序前的元素作为value插入至无序字典中，从而可以得到字母异位词的组合。
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> sm;
		int num = strs.size();
		for (int i = 0; i < num; ++i) {
			string value = strs[i];
			sort(value.begin(), value.end());
			sm[value].push_back(strs[i]);
		}
		//最后将map中的组合添加至result中返回
		for (auto iter = sm.begin(); iter != sm.end(); ++iter) {
			result.push_back(iter->second);
		}
		return result;
	}
};