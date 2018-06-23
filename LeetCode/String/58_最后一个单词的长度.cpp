// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
58. 最后一个单词的长度
https://leetcode-cn.com/problems/length-of-last-word/description/

给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
*/

/*整体思路是 :	没什么好说的，反向查找即可保证在线性时间复杂度完成。
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int num = s.size(), result = 0;
		int i = num - 1;
		//首先跳过末尾的空格
		for (i; i >= 0; --i) {
			if (s[i] == ' ')
				continue;
			break;
		}
		//从末尾第一个非空字符开始反向查找直到出现空格或到达字符串头，注意，只有一个单词
		//时其既是第一个单词也是最后一个单词
		for (; i >= 0; --i) {
			if (s[i] == ' ')
				break;
			++result;
		}
		return result;
	}
};