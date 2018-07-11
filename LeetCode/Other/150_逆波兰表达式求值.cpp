// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
150. 逆波兰表达式求值
https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/

根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
	整数除法只保留整数部分。
	给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/

/*整体思路是 :	利用栈实现，碰到数字入栈，碰到符号则从栈中出栈两个元素进行运算，并将结果
压栈。最终栈中只有一个元素，即为结果。
*/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> is;
		for (int i = 0; i < tokens.size(); ++i) {
			string value = tokens[i];
			int value_1 = 0, value_2 = 0, result = 0;
			if (tokens[i].size() == 1 && (tokens[i][0]<'0' || tokens[i][0]>'9')) {
				value_1 = is.top();is.pop();
				value_2 = is.top();is.pop();
				switch (value[0]) {
				case '+':
					result = value_1 + value_2;
					is.push(result);
					break;
				case '-':
					result = value_2 - value_1;
					is.push(result);
					break;
				case '*':
					result = value_2 * value_1;
					is.push(result);
					break;
				case '/':
					result = value_2 / value_1;
					is.push(result);
					break;
				}
			}
			else {
				int temp = stoi(value);
				is.push(temp);
			}
		}
		return is.top();
	}
};