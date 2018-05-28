// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
242. 有效的字母异位词
https://leetcode-cn.com/problems/valid-anagram/description/

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
*/

/*没什么好说的，唯一要注意的是此处认为两个字符串完全相同也是字母异位词
*/
class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> bucket(26, 0);
		for (auto x : s)
			++bucket[x - 'a'];
		for (auto x : t)
			--bucket[x - 'a'];
		for (auto x : bucket) {
			if (x != 0)
				return false;
		}
		return true;
	}
};