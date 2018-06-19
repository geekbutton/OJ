// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
14. 最长公共前缀
https://leetcode-cn.com/problems/longest-common-prefix/description/

编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
*/

/*整体思路是 :	逐个匹配前缀，每次从头匹配到前缀的最大长度以节省时间。
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int num = strs.size();
		if (num == 0)
			return "";
		if (num == 1)
			return strs[0];
		string result;
		int temp = min(strs[0].size(), strs[1].size());
		for (int i = 0; i < temp; ++i) {
			if (strs[0][i] != strs[1][i])
				break;
			result += strs[0][i];
		}
		// 数组中逐元素查找，最大查找长度为当前前缀的长度。且当前缀为空时提前退出
		for (int i = 2; i < num && result.size(); ++i) {
			for (int j = 0; j < result.size(); ++j) {
				if (strs[i][j] == result[j])
					continue;
				result.resize(j);
				break;
			}
		}
		return result;
	}
};