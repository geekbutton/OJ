// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
140. 单词拆分 II
https://leetcode-cn.com/problems/word-break-ii/description/

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，
使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：
	分隔时可以重复使用字典中的单词。
	你可以假设字典中没有重复的单词。
*/

/*整体思路是 :	首先利用习题139的单词拆分来判断给出的字符串能否使用字典中的单词组成句子。
若不能则提前退出避免时间开销；若能，则使用DFS遍历所有的可能组合。
*/
void GetSentences(string, string, vector<string>&, unordered_set<string>&);
bool Check(string, unordered_set<string>&);
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> ss(wordDict.begin(), wordDict.end());
		vector<string> result;
		string  value;
		if (Check(s, ss)) {		//若能组成句子，调用函数获得所有解
			GetSentences(s, value, result, ss);
		}
		return result;
	}
};
//习题139的动态规划算法判断是否能组成句子
bool Check(string s, unordered_set<string>& ss) {
	vector<int> iv(s.size() + 1, 0);
	iv[0] = 1;
	int index = s.size() + 1;
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (iv[j] == 0)
				continue;
			string value = s.substr(j, i - j);
			if (ss.find(value) != ss.end()) {
				iv[i] = 1;
				break;
			}
		}
	}
	return iv[s.size()];
}
//DFS算法，遍历所有可能的情况
void GetSentences(string s, string value, vector<string>& result, unordered_set<string>& ss) {
	for (int i = 0; i < s.size(); ++i) {
		string temp = s.substr(0, i + 1);
		if (ss.find(temp) == ss.end())
			continue;
		if (temp.size() == s.size()) {		//单独处理只有完整的当前字符串才在字典中的情况
			value += temp;		//此时把整个字符串输入作为结果添加到value上，注意这是最后一个，因此不用添加空格
			result.push_back(value);
			return;
		}
		string res_str = s.substr(i + 1);
		value += temp + " ";		//记住添加空格
		GetSentences(res_str, value, result, ss);
		value.resize(value.size() - temp.size() - 1);	//记住处理完成后将value恢复至添加前的状态
	}
}