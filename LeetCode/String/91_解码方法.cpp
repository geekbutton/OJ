// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
91. 解码方法
https://leetcode-cn.com/problems/decode-ways/description/

一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。注意0不对应任何字符
*/

/*整体思路是 :	利用类似动态规划的想法进行求解，关键需要注意的是对0的处理。
*/
class Solution {
public:
	int numDecodings(string s) {
		int i = 1;
		vector<int> iv(s.size(), 0);
		//如果首字符为0，直接返回0表示错误
		if (s[0] == '0')
			return 0;
		for (i; i < s.size(); ++i) {
			//任何时刻，如果s[i]为0，则s[i-1]只可能是1或2，出现其他数字则s[i]的0都无法匹配
			//到任何数据，因此直接返回0 。
			if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] - '0' > 2))
				return 0;
			//如果s[i]不为0，且s[i]和s[i-1]组成的数字大于26，则这两个数字必然分别解析
			//因此iv[i]=iv[i-1];
			if (s[i] - '0' + 10 * (s[i - 1] - '0') > 26) {
				iv[i] = iv[i - 1];
				continue;
			}
			//如果S[i-1]为0，则s[i]必然只能单独解析，因此iv[i]=iv[i-1];
			if (s[i - 1] == '0') {
				iv[i] = iv[i - 1];
				continue;
			}
			if (s[i] == '0') {
				//如果s[i]=0，前一元素和0组合小于26，则前一元素必然和0组合，因此
				//iv[i]=iv[i-1];
				if (i - 2 >= 0 && s[i - 2] - '0' <= 2 && s[i - 2] - '0' > 0) {
					iv[i] = iv[i - 2];
					continue;
				}
				iv[i] = iv[i - 1];
				continue;
			}
			//s[i]和s[i-1]组成的数字小于26且不存在0 iv[i] = iv[i-1]+iv[i-2]+1
			//iv[i-1]表示s[i]单独解析时的编码方法，iv[i-2]表示s[i]，s[i-1]一起
			//解析时的编码方法，注意理解加1。
			iv[i] = iv[i - 1] + 1;
			if (i >= 2) {
				iv[i] += iv[i - 2];
			}
		}
		return iv[s.size() - 1] + 1;
	}
};