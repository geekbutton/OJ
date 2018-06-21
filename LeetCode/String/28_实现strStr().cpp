// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
28. 实现strStr()
https://leetcode-cn.com/problems/implement-strstr/description/

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回  -1。当 needle 是空字符串时我们应当返回 0 。
*/

/*整体思路是 :	利用KMP算法查找子串，关键在于如何最快构造部分匹配表，提交发现部分匹配表的
构造严重影响算法的整体时间复杂度。
*/
vector<int> Partial_matching(string);
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		vector<int> iv(needle.size(), 0);
		iv = Partial_matching(needle);

		int match_index = 0;
		int i = 0;
		for (i = 0; i < haystack.size() && match_index < needle.size();) {
			if (match_index == 0 && haystack[i] != needle[0]) {
				++i;
				continue;
			}
			else if (match_index == 0 && haystack[i] == needle[0]) {
				match_index = 1;
				++i;
				continue;
			}
			else if (haystack[i] == needle[match_index]) {
				++i; ++match_index;
				continue;
			}
			else {
				match_index = iv[match_index - 1];
				continue;
			}
		}
		if (match_index == needle.size())
			return i - needle.size();
		return -1;
	}
};
//注意这里求解部分匹配表的方法，一次即可求解所有值
vector<int> Partial_matching(string s) {
	vector<int> iv(s.size(), 0);
	if (s.size() == 0)
		return iv;
	int max_length = 0;
	//对应三种情况，i对应字符串匹配头，j对应当前匹配位置
	for (int i = 0, j = 1; j < s.size();) {
		if (s[i] == s[j])		//相等则同时移动i和j
			iv[j++] = ++i;
		else if (i)				//不相等且i不在字符串头部，则重新指定i的位置。这是最难理解的一个，结合部分匹配的性质理解
			i = iv[i-1];
		else ++j;				//不相等且i仍然在字符串头部则保持i，往后移动j
	}
	return iv;
}