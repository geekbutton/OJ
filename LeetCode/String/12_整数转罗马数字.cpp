// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
12. ����ת��������
https://leetcode-cn.com/problems/integer-to-roman/description/

������ת������������
*/

/*����˼·�� :	�����������ֵ�ת������ת�����ɣ���Ҫע�����������������µ�д����
*/
class Solution {
public:
	string intToRoman(int num) {
		string result;
		while (num) {
			if (num >= 1000) {
				result += "M";
				num -= 1000;
				continue;
			}
			else if (num >= 500) {
				if (num >= 900) {
					result += "CM";
					num -= 900;
					continue;
				}
				result += "D";
				num -= 500;
				continue;
			}
			else if (num >= 100) {
				if (num >= 400) {
					result += "CD";
					num -= 400;
					continue;
				}
				result += "C";
				num -= 100;
				continue;
			}
			else if (num >= 50) {
				if (num >= 90) {
					result += "XC";
					num -= 90;
					continue;
				}
				result += "L";
				num -= 50;
				continue;
			}
			else if (num >= 10) {
				if (num >= 40) {
					result += "XL";
					num -= 40;
					continue;
				}
				result += "X";
				num -= 10;
				continue;
			}
			else if (num >= 5) {
				if (num >= 9) {
					result += "IX";
					num -= 9;
					continue;
				}
				result += "V";
				num -= 5;
				continue;
			}
			else if (num >= 1) {
				if (num >= 4) {
					result += "IV";
					num -= 4;
					continue;
				}
				result += "I";
				num -= 1;
				continue;
			}
		}
		return result;
	}
};