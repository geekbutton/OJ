// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
20. 有效的括号
https://leetcode-cn.com/problems/valid-parentheses/description/

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。
	注意空字符串可被认为是有效字符串。
*/

/*整体思路是 :	利用栈，典型的利用入栈出栈操作进行对应匹配的问题。
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> cs;
		for (int i = 0; i < s.size(); ++i) {
			char value = s[i];
			if (value == '(' || value == '[' || value == '{') {
				cs.push(value);
				continue;
			}
			else {
				if (!cs.size())
					return false;
				switch (value) {
				case ')':
					if (cs.top() == '(') {
						cs.pop();
						continue;
					}return false;
				case ']':
					if (cs.top() == '[') {
						cs.pop();
						continue;
					}return false;
				case '}':
					if (cs.top() == '{') {
						cs.pop();
						continue;
					}return false;
				}
			}
		}
		//注意最终的退出条件，当栈中元素为空时才能返回True，如果遍历到最后一个元素后
		//栈中还有元素，则返回FALSE
		if (cs.size())
			return false;
		return true;
	}
};