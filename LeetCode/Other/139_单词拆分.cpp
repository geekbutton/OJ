// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
139. 单词拆分
https://leetcode-cn.com/problems/word-break/description/

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格
拆分为一个或多个在字典中出现的单词。

说明：
	拆分时可以重复使用字典中的单词。
	你可以假设字典中没有重复的单词。
*/

/*整体思路是 :	利用动态规划进行求解。在计算dp[i]的时候，我们已经知道dp[0],dp[1],…,dp[i-1],
如果以i为结尾的j~i子串是满足条件的，并且0~j的子串也是在字典中的，那么dp[i]就是true
*/
bool CheckWord(string&, const unordered_set<string>&);
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<int> iv(s.size()+1,0);
		iv[0] = 1;	//第0个元素对应位置置为1，这样后面程序会判断从字符串头到当前位置是否能组成单词
		unordered_set<string> Dict( wordDict.begin(),wordDict.end() );
		int index = s.size() + 1;
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 0; j < i; ++j) {		//判断从任意一个dp[j]=1的字符后到位置i能否构成单词
				if (iv[j] == 0)
					continue;
				string value = s.substr(j, i - j);
				if (Dict.find(value) != Dict.end()) {
					iv[i] = 1;
					break;
				}
			}
		}
		return iv[s.size()];
	}
};