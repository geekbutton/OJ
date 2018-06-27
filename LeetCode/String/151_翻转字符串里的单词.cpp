// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
151. 翻转字符串里的单词
https://leetcode-cn.com/problems/reverse-words-in-a-string/description/

给定一个字符串，逐个翻转字符串中的每个单词。
示例:
	输入: "the sky is blue",
	输出: "blue is sky the".

说明:
	无空格字符构成一个单词。
	输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
	如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 时间复杂度的原地解法。
*/

/*整体思路是 :	按顺序遍历字符串，先逐单词翻转，最后整个字符串翻转即可得到翻转后的字符串。
要注意的是字符串中多个空格的处理，在这里我采用的是双指针逐位移位的方式来处理。对于头尾的
空字符直接在开始时跳过，从第一个非空字符处理到最后一个非空字符。
*/
class Solution {
public:
	void reverseWords(string &s) {
		int l = 0, r = 0;
		//跳过开头的空字符
		while (r < s.size()) {
			if (s[r] == ' ') {
				++r; continue;
			}
			break;
		}
		int l_index = r, r_index = s.size() - 1;		//首尾非空元素索引
		l = r;
		//跳过结尾的空字符
		while (r_index >= l_index) {
			if (s[r_index] == ' ') {
				--r_index;
				continue;
			}
			break;
		}
		//遍历字符串，逐单词翻转
		for (r; r < r_index; ++r) {
			if (s[r] == ' ') {
				if (l == r) {
					l = r + 1;
					continue;
				}
				reverse(s.begin() + l, s.begin() + r);
				l = r + 1;
			}
		}
		if (l < r)		//注意处理最后一个单词翻转
			reverse(s.begin() + l, s.begin() + r + 1);
		s = s.substr(l_index, r_index - l_index + 1);
		reverse(s.begin(), s.end());

		//通过两个指针采用in-place的方式处理多余的空白字符
		l = 1, r = 1;
		for (; r < s.size(); ++r) {
			if (s[r] == ' ' && s[r - 1] == ' ')
				continue;
			s[l] = s[r];
			++l;
		}
		if (s.size() > l)
			s.resize(l);
	}
};