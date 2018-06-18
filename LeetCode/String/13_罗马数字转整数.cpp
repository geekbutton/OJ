// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
13. ��������ת����
https://leetcode-cn.com/problems/roman-to-integer/description/

����������ת��������
*/

/*����˼·�� :	�����������ֵ�ת������ת�����ɣ���Ҫע�����������������µ�д����12���
�������⡣
*/
class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		int num = s.size();
		for (int i = 0; i < s.size(); ++i) {
			switch (s[i]) {
			case 'M':result += 1000; break;
			case 'D':result += 500; break;
			case 'C':
				if (i < num - 1 &&  s[i + 1] == 'D') {
					result += 400;
					++i;
				}
				else if (i < num - 1 &&  s[i + 1] == 'M') {
					result += 900;
					++i;
				}
				else result += 100;
				break;
			case 'L':result += 50; break;
			case 'X':
				if (i < num - 1 && s[i + 1] == 'L') {
					result += 40;
					++i;
				}
				else if (i < num - 1 && s[i + 1] == 'C') {
					result += 90;
					++i;
				}
				else result += 10;
				break;
			case 'V':result += 5; break;
			case 'I':
				if (i < num - 1 && s[i + 1] == 'V') {
					result += 4;
					++i;
				}
				else if (i < num - 1 && s[i + 1] == 'X') {
					result += 9;
					++i;
				}
				else result += 1;
				break;
			}
		}
		return result;
	}
};