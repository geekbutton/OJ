// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
87. 扰乱字符串
https://leetcode-cn.com/problems/scramble-string/description/

具体描述见相关题目页。
*/

/*整体思路是 :	思路是利用递归算法来实现，其思路是如果s1和s2是扰乱字符串，则必定存在一个切分
位置将s1分为s1_1和s1_2，将s2分为s2_1和s2_2。此时s1_1和s2_1应为扰乱字符串，且s1_2和s2_2应为扰乱
字符串。或者s1_1和s2_2应为扰乱字符串，且s1_2和s2_1应为扰乱字符串。
*/
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)				//如果相等则返回true
			return true;
		if (s1.size() != s2.size())	//如果s1和s2大小都不等，则必然不是扰乱字符串
			return false;
		//注意这里，之所以将两个字符串排序后比较是为了更快速的判断出两者不是扰乱字符串
		//的情形，避免对两个不可能是扰乱字符串的字符串进行拆分判断，事实证明如果没有这种
		//处理，最终会超时。
		string temp_1 = s1, temp_2 = s2;
		sort(temp_1.begin(), temp_1.end());
		sort(temp_2.begin(), temp_2.end());
		if (temp_1 != temp_2)
			return false;
		for (int i = 1; i < s1.size(); ++i) {
			string s1_1 = s1.substr(0, i);
			string s1_2 = s1.substr(i);
			string s2_1 = s2.substr(0, i);
			string s2_2 = s2.substr(i);
			//先处理头对头，尾对尾的情况
			if (isScramble(s1_1, s2_1) && isScramble(s1_2,s2_2))	//注意必须要两个分隔后的子串都满足才行
				return true;
			s2_1 = s2.substr(0, s1.size() - i);
			s2_2 = s2.substr(s1.size() - i);
			//不满足时处理头对尾，尾对头的情况
			if (isScramble(s1_1, s2_2) && isScramble(s1_2, s2_1))
				return true;
		}
		return false;
	}
};