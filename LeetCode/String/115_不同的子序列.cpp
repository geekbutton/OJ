// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
115. 不同的子序列
https://leetcode-cn.com/problems/distinct-subsequences/description/

给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
*/

/*整体思路是 :	利用动态规划进行求解。以字符串T的字符作为行，S的字符作为列，同时添加一个空行
空列。其中第0行全为1，第0列除第一个外全为0。动态规划状态转移分为两种情况：
	1.	s[j-1]!=t[i-1]，即两个字符串当前尾字符不等，则此时iv[i][j]=iv[i][j-1]
	2.	s[j-1]==t[i-1]，即两个字符串当前尾字符相等，此时iv[i][j]=iv[i-1][j-1]+iv[i][j-1],即
		当前T出现在S中的次数等于选择了S和T尾字符后其余字符的出现次数+没有选择S的尾字符时其余
		字符的出现次数。
*/
class Solution {
public:
	int numDistinct(string s, string t) {
		int num1 = s.size(), num2 = t.size();
		vector<vector<int>> iv(num2 + 1, vector<int>(num1 + 1, 0));
		for (int i = 0; i <= num1; ++i)
			iv[0][i] = 1;
		for (int i = 1; i <= num2; ++i)
			iv[i][0] = 0;

		for (int i = 1; i <= num2; ++i) {
			for (int j = i; j <= num1; ++j) {
				if (s[j - 1] != t[i - 1]) {
					iv[i][j] = iv[i][j - 1];
					continue;
				}
				iv[i][j] = iv[i - 1][j - 1] + iv[i][j - 1];
			}
		}
		return iv[num2][num1];
	}
};
