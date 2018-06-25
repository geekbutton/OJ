// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
93. 复原IP地址
https://leetcode-cn.com/problems/restore-ip-addresses/description/

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
*/

/*整体思路是 :	利用类似深度优先遍历的方法来实现，一个IP地址包括四个字段，每求解一个字段
就先求得其最长和最短长度，在此范围内遍历其可能的取值。
*/
void GetIP(string, string, vector<string>&, int);
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12 || s.size() < 4)
			return vector<string>();
		vector<string> result;
		int level = 4;
		string value;
		GetIP(s, value, result, level);
		return result;
	}
};

void GetIP(string s, string value, vector<string>& result, int level) {
	if (level == 1) {	//处理IP地址的最后一个字段
		//如果以0开头，长度又不为1，则不合法
		if (s.size() != 1 && s[0] == '0')
			return;
		if (s.size() == 3) {
			//如果长度为三，则要判断是否合法
			if ((s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0' > 255)
				return;
		}
		value += s;		//合法则添加最后一个字段，并将结果添加至result中
		result.push_back(value);
		return;
	}
	int num = s.size();
	//根据当前字符串的长度和一个IP字段允许的最大最小长度，求对应字段的长度范围
	int i = max(1, num - (level - 1) * 3);		//最小长度
	int max_len = min(3, num - (level - 1));	//最大长度
	for (i; i <= max_len; ++i) {
		//先判断是否合法
		if (s[0] == '0' && i!=1)
			break;
		if (i == 3) {
			if ((s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0' > 255)
				return;
		}
		//合法则更新IP地址，同时继续递归求解下一个字段
		string temp = s.substr(0, i);
		value += temp + ".";
		GetIP(s.substr(i), value, result, level - 1);
		value.resize(value.size() - i - 1);		//记得返回时删除刚才添加的字段
	}
}