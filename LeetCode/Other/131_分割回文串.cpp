// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
131. 分割回文串
https://leetcode-cn.com/problems/palindrome-partitioning/description/

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。
*/

/*整体思路是 :	还是一个利用DFS进行求解的问题，需要两个函数，一个用于判断回文串，一个用于
递归分割回文串。
*/
bool Check(string);
void Partition(string, vector<string>, vector<vector<string>>&);
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> value;
		if (Check(s))	//原始字符串单独处理
			result.push_back(vector<string>{s});
		Partition(s, value, result);
		return result;
	}
};

bool Check(string s) {	//判断回文串
	int num = s.size();
	if (num == 1)
		return true;
	for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
		if (s[i] == s[j])
			continue;
		return false;
	}
	return true;
}

void Partition(string s, vector<string> value, vector<vector<string>>& result) {
	//递归求解回文串，注意退出条件
	for (int i = 1; i < s.size(); ++i) {
		string left = s.substr(0, i);
		string right = s.substr(i);
		if (Check(left)) {	//首先分割出的左子串要求是回文串才能继续分割右子串
			value.push_back(left);
			if (Check(right)) {	//若右子串也是回文串，首先当前结果满足，然后继续递归右子串
				value.push_back(right);
				result.push_back(value);
				value.pop_back();
			}
			Partition(right, value, result);
			value.pop_back();
		}
	}
}