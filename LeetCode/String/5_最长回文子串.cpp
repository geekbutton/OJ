// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
5. 最长回文子串
https://leetcode-cn.com/problems/longest-palindromic-substring/description/

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
*/

/*整体思路是 :	第一种方法，从最大序列开始逐个遍历，返回第一个回文串即为最大回文串，但该方法
时间复杂度较高。第二种方法：MMNACHER算法(https://www.cnblogs.com/TenosDoIt/p/3675788.html)
*/
class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.size();
		if (!length)
			return string();
		while (length) {
			for (int i = 0; i < s.size() - length + 1; ++i) {
				int r = i + length - 1;
				int j = i;
				for (; j < i + length / 2; ++j) {
					if (s[j] != s[r])
						break;
					--r;
				}
				if (j == i + length / 2) {
					return s.substr(i, length);
				}
			}
			--length;
		}
	}
};

string preprocess(string&);
class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.size();
		int mx = 0, id = 0;
		string res = preprocess(s);
		vector<int> p(res.size(), 0);
		for (int i = 1; i < res.size(); ++i) {
			//关键性语句
			p[i] = mx > i ? (min(p[2 * id - i], mx - i)) : 1;
			//遍历看能否继续以i为中心匹配
			while ((i - p[i] >= 0) && res[i + p[i]] == res[i - p[i]])
				++p[i];
			//如果匹配到的最右值超过了之前的最右值，则更新最右值和对应索引
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		//遍历子串长度数组，找到最长子串p[i]-1
		int max_length = 0, index = 0;
		for (int i = 1; i < res.size(); ++i) {
			if (p[i] > max_length) {
				max_length = p[i];
				index = i;
			}
		}
		return s.substr((index - max_length + 1) / 2, max_length - 1);
	}
};
//给原始字符串添加'#'
string preprocess(string& s) {
	string res;
	for (int i = 0; i < s.size(); ++i) {
		res.push_back('#');
		res.push_back(s[i]);
	}
	res.push_back('#');
	return res;
}