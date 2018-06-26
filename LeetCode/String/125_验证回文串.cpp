// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
125. 验证回文串
https://leetcode-cn.com/problems/valid-palindrome/description/

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
*/

/*整体思路是 :	判定回文串的额外条件版。首先遍历字符串去掉所有不考虑的字符，同时将所有大写字符
转换成小写字符(或相反，因为本题中不区分大小写)。此时即可按照处理普通回文串的方法进行处理，即定
义头尾指针同时向中间移动并判定其所指向的内容是否相等，不相等可以提前退出。
*/
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)
			return true;
		string value;
		for (int i = 0; i < s.size(); ++i) {
			if ((s[i] >= '0' && s[i] <= '9'))
				value.push_back(s[i]);
			else if (s[i] >= 'A' && s[i] <= 'Z')
				value.push_back(s[i] + 32);
			else if (s[i] >= 'a' && s[i] <= 'z')
				value.push_back(s[i]);
		}
		for (int i = 0, j = value.size() - 1; i <= j; ++i, --j) {
			if (value[i] != value[j])
				return false;
		}
		return true;
	}
};