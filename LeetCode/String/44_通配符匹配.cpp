// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
44. 通配符匹配
https://leetcode-cn.com/problems/wildcard-matching/description/

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
	'?' 可以匹配任何单个字符。
	'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。
*/

/*整体思路是 :	类似习题10的正则表达式。整体思路还是利用动态规划进行求解。在这里，分成了
三种情况进行处理，同时对第一个字符进行额外判定。
	1.	通配符不为*或？，则iv[i][i] = iv[i - 1][j - 1] && (p[j - 1] == s[i - 1])，即
		取决于前一个位置是否成功匹配和当前字符能否成功匹配。
	2.	通配符为？，iv[i][j] = iv[i - 1][j - 1]，即取决于前一个位置上能否成功匹配。
	3.	通配符为*，只要前一通配符能成功匹配任意长度的待匹配字符则置1，即任意iv[k][j-1]为1
		则iv[i][j]为1(k = 0,...,i)。
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		int count1 = s.size(), count2 = p.size();
		vector<vector<int>> iv(count1 + 1, vector<int>(count2 + 1, 0));
		iv[0][0] = 1;
		int flag = 1;
		//首先判定待匹配字符的第一个字符
		for (int i = 0; i < count2; ++i) {
			if (p[i] == '*') {			//通配符为*则对应位置1，其职能出现在通配符开头或紧跟在第一个匹配符后面
				iv[0][i + 1] = 1;
				if (count1 > 0)
					iv[1][i + 1] = 1;
				continue;
			}
			if (flag && count1 > 0 && (p[i] == s[0] || p[i] == '?')) {	//找到第一个不为*的字符进行匹配
				iv[1][i + 1] = 1;
				flag = 0;
				continue;
			}
			break;
		}
		//三种动态规划状态转移方程
		for (int i = 2; i <= count1; ++i) {
			for (int j = 1; j <= count2; ++j) {
				if (p[j - 1] != '*' && p[j - 1] != '?') {
					iv[i][j] = iv[i - 1][j - 1] && (p[j - 1] == s[i - 1]);
				}
				else if (p[j - 1] == '?')
					iv[i][j] = iv[i - 1][j - 1];
				else if (p[j - 1] == '*') {
					for (int k = 0; k <= i; ++k) {
						if (iv[k][j - 1]) {
							iv[i][j] = 1;
							break;
						}
					}
				}
			}
		}
		return iv[count1][count2];
	}
};