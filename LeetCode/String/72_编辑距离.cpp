// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
72. 编辑距离
https://leetcode-cn.com/problems/edit-distance/description/

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
	插入一个字符
	删除一个字符
	替换一个字符
*/

/*整体思路是 :	仍然是利用动态规划的想法进行求解。对于第0行和第0列，对应编辑距离即为
此时的Word1长度或word2长度。对于word1[i-1]==word2[j-1]的情况，dp[i][j]=dp[i-1][j-1]即
其编辑距离取决于在前个字符上转换进行的最少操作数(因为相等，所以在该字符上不需要任何操作)。
对于不等的情况，分为三种情况取最小值：
	1.	替换一个字符，则dp[i][j] = dp[i-1][j-1]+1，即前一字符转换成功的基础上进行一个替换操作
	2.	删除一个字符，则dp[i][j] = dp[i - 1][j] + 1，即在前一字符转换成功的基础上删除本字符
		word1[i-1]
	3.	插入一个字符，则dp[i][j] = dp[i][j - 1] + 1，即成功转换了前一字符，在其基础上添加一个
		字符转换=新增加的word2[j-1]
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int i = 0, j = 0;
		int count = 0;
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word2.size(); ++i) {
			dp[0][i] = i;
		}
		for (int i = 0; i <= word1.size(); ++i) {
			dp[i][0] = i;
		}
		for (int i = 1; i <= word1.size(); ++i) {
			for (int j = 1; j <= word2.size(); ++j) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {	//转换的三种操作
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}
};