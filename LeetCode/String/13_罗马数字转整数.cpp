// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
13. 罗马数字转整数
https://leetcode-cn.com/problems/roman-to-integer/description/

将罗马数字转换成数字
*/

/*整体思路是 :	按照罗马数字的转换规则转换即可，需要注意的是六种特殊情况下的写法。12题的
镜像问题。
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