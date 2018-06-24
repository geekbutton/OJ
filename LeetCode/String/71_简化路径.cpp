// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
71. 简化路径
https://leetcode-cn.com/problems/simplify-path/description/

给定一个文档 (Unix-style) 的完全路径，请进行路径简化。
*/

/*整体思路是 :	利用getline按照/分隔符读取字符串，根据字符串判断操作。如果字符串为
空或"."则直接跳过。如果字符串为".."则删除前一元素，其他情况则添加该字符串
*/
class Solution {
public:
	string simplifyPath(string path) {
		string res, tmp;
		vector<string> stk;				//利用一个vector保存每次解析出的字符串，便于删除操作
		stringstream ss(path);
		while (getline(ss, tmp, '/')) {
			if (tmp == "" or tmp == ".") continue;
			if (tmp == ".." and !stk.empty()) stk.pop_back();
			else if (tmp != "..") stk.push_back(tmp);
		}
		for (auto str : stk) res += "/" + str;
		return res.empty() ? "/" : res;
	}
};