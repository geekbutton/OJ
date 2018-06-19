// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
17. 电话号码的字母组合
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

/*整体思路是 :	深度优先遍历，遍历所有的排列组合情况。
*/
void Combination(string&, int, vector<vector<string>>&, string&, vector<string>&);
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (!digits.size())
			return vector<string>();
		unordered_set<string> ss;
		vector<string> result;
		string temp_result;
		vector<vector<string>> lib{ {"a","b","c"},{"d","e","f"},{ "g","h","i" },
							{ "j","k","l" },{ "m","n","o" },{ "p","q","r","s" },
							{ "t","u","v" },{ "w","x","y","z" } };
		Combination(digits, 0, lib, temp_result, result);
		return result;
	}
};

//实现深度优先遍历
void Combination(string& digits, int index, vector<vector<string>>& lib, string& temp_result, vector<string>& result) {
	int map_index = digits[index] - '0';
	vector<string> temp_lib = lib[map_index - 2];
	// 当遍历到的元素为最后一个元素则将当前组合结果添加至最终结果中
	if (index == digits.size() - 1) {
		for (int i = 0; i < temp_lib.size(); ++i) {
			temp_result += (temp_lib[i]);
			result.push_back(temp_result);
			temp_result.pop_back();			//注意每次退出时删除最后一个元素
		}
	}
	else {
		for (int i = 0; i < temp_lib.size(); ++i) {
			temp_result += (temp_lib[i]);	//增加当前元素，继续向下一个值遍历
			Combination(digits, index + 1, lib, temp_result, result);
			temp_result.pop_back();			//注意每次退出时删除最后一个元素
		}
	}
}