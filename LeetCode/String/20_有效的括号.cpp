// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
20. ��Ч������
https://leetcode-cn.com/problems/valid-parentheses/description/

����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
	�����ű�������ͬ���͵������űպϡ�
	�����ű�������ȷ��˳��պϡ�
	ע����ַ����ɱ���Ϊ����Ч�ַ�����
*/

/*����˼·�� :	����ջ�����͵�������ջ��ջ�������ж�Ӧƥ������⡣
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
		//ע�����յ��˳���������ջ��Ԫ��Ϊ��ʱ���ܷ���True��������������һ��Ԫ�غ�
		//ջ�л���Ԫ�أ��򷵻�FALSE
		if (cs.size())
			return false;
		return true;
	}
};