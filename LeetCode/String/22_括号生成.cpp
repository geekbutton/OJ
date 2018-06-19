// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
22. 括号生成
https://leetcode-cn.com/problems/generate-parentheses/description/

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：
*/

/*整体思路是 :	类似17题的解法，配合20题判断括号的合法性，回溯算法的典型例题。
*/
void Combination(int, string, vector<string>&, stack<char>);
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (!n)
			return vector<string>();
		stack<char> cs;
		vector<string> result;
		string temp_str;
		int count = 0;
		Combination(n, temp_str, result, cs);
		return result;
	}
};
//注意temp_str和cs在如下写法中不能是传引用
void Combination(int n, string temp_str, vector<string>& result, stack<char> cs) {
	if (!n) {			//如果n等于0，则说明所有左括号已经添加完毕，此时只能添加右括号，返回结果
		for (int i = 0; i < cs.size(); ++i)
			temp_str += ')';		//根据栈中左括号的数目添加右括号，添加相应最终结果
		result.push_back(temp_str);
		return;
	}
	if (cs.size() == 0) {		//如果栈为空，则此时只能添加左括号
		cs.push('(');
		temp_str += '(';
		Combination(n - 1, temp_str, result, cs);
	}	
	else {			//如果栈不为空，则可以添加左括号或添加右括号
		cs.push('(');
		temp_str += '(';
		Combination(n - 1, temp_str, result, cs);	//添加左括号，n减1
		cs.pop();			//添加右括号，删除刚才添加的左括号及和右括号完成匹配的左括号
		cs.pop();			//所以删除两次
		temp_str.pop_back();	//删除刚才添加的左括号
		temp_str += ')';		//添加匹配的右括号
		Combination(n, temp_str, result, cs);	//继续遍历，此时因为没有添加左括号，因此n保持不变
	}
}