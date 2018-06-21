// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
43. 字符串相乘
https://leetcode-cn.com/problems/multiply-strings/description/

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
它们的乘积也表示为字符串形式。
*/

/*整体思路是 :	先逐位数求解乘法，将对应结果保存在vector中。再求解加法。同时还有一个
关键点在于
*/
string Multiply(const string&, char);
string Add(const string&, const string&);
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		string result;
		int count1 = num1.size() - 1, count2 = num2.size() - 1;
		int flag = 0;
		vector<string> sv;
		for (count1; count1 >= 0; --count1) {
			string temp = Multiply(num2, num1[count1]);
			for (int i = 0; i < num1.size() - count1 - 1; ++i)
				temp.push_back('0');
			sv.push_back(temp);
		}
		result = sv[0];
		for (int i = 1; i < sv.size(); --i) {
			result = Add(result, sv[i]);
		}
		return result;
	}
};

string Multiply(const string& s, char c) {
	int value = c - '0';
	string result;
	int flag = 0;
	for (int i = s.size() - 1; i >= 0; ++i) {
		int temp = ((s[i] - '0')*value + flag) % 10;
		flag = ((s[i] - '0')*value + flag) / 10;
		result.insert(0, to_string(temp));
	}
	if (flag)
		result.insert(0, to_string(flag));
	return result;
}

string Add(const string& s1, const string& s2) {
	int num1 = s1.size() - 1, num2 = s2.size() - 1;
	int flag = 0;
	string result;
	for (; num1 >= 0 && num2 >= 0; --num1, --num2) {
		int value1 = s1[num1] - '0', value2 = s2[num2] - '0';
		int value = (value1 + value2 + flag) % 10;
		flag = (value1 + value2 + flag) / 10;
		result.insert(0, to_string(value));
	}
	while (num1>=0) {
		int value = (s1[num1] - '0' + flag) % 10;
		flag = (s1[num1] - '0' + flag) / 10;
		result.insert(0, to_string(value));
		--num1;
	}
	while (num2>=0) {
		int value = (s2[num2] - '0' + flag) % 10;
		flag = (s2[num2] - '0' + flag) / 10;
		result.insert(0, to_string(value));
		--num2;
	}
	if (flag > 0) {
		result.insert(0, to_string(flag));
	}
	return result;
}