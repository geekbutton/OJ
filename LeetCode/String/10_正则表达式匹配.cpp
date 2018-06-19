// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
10. 正则表达式匹配
https://leetcode-cn.com/problems/regular-expression-matching/description/

给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
*/

/*整体思路是 :	利用动态规划求解，假设iv[i][j]表示字符串s[0..i)是否匹配表达式p[0...j),
状态转移方程为：
	1.	iv[i][j] = iv[i-1][j-1], 如果p[j-1]!='*'且(s[i-1]==p[i-1] || p[i-1]=='.')。即当
	当前匹配字符不为*通配符时，如果当前匹配字符等于当前字符，则能否成功匹配取决于前一状态。
	2.	iv[i][j] = iv[i][j-2], 如果p[j-1]=='*'且其前一字符从未出现，则能否成功匹配取决于
	在*符之前的之前的元素能否成功匹配。
	3.	iv[i][j] = iv[i-1][j] && (s[i-1]==p[j-2] || p[j-2] == '.'), 如果p[j-1]=='*'
	且其通配字符出现过至少一次。此时能否成功匹配取决于p[j-2]对应元素能否成功匹配s[i-1]
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool> > iv(m + 1, vector<bool>(n + 1, false));
		iv[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] == '*')
					iv[i][j] = iv[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && iv[i - 1][j]);
				else iv[i][j] = i > 0 && iv[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				return iv[m][n];
	}
};