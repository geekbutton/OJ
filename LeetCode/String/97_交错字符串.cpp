// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
97. 交错字符串
https://leetcode-cn.com/problems/interleaving-string/description/

给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
*/

/*整体思路是 :	利用动态规划进行求解。
*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int num1 = s1.size(), num2 = s2.size();
		if (num1 + num2 != s3.size())
			return false;
		vector<vector<int>> iv(num1 + 1, vector<int>(num2 + 1, 0));
		iv[0][0] = 1;			//设置iv[0][0]为1
		for (int i = 0; i <= num1; ++i) {
			for (int j = 0; j <= num2; ++j) {
				if (i + j == 0)
					continue;
				int index = i + j;		//表示当前在s3中的匹配位置
				if (i > 0)
					iv[i][j] = (iv[i - 1][j] && (s3[index - 1] == s1[i - 1]));
				if (j > 0)
					iv[i][j] = iv[i][j] || iv[i][j - 1] && (s3[index - 1] == s2[j - 1]);
			}
		}
		return iv[num1][num2];
	}
};
