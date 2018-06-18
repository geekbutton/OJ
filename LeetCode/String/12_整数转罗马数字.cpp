// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
12. 整数转罗马数字
https://leetcode-cn.com/problems/integer-to-roman/description/

将数字转换成罗马数字
*/

/*整体思路是 :	按照罗马数字的转换规则转换即可，需要注意的是六种特殊情况下的写法。
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