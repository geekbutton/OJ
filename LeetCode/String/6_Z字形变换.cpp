// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
6. Z字形变换
https://leetcode-cn.com/problems/zigzag-conversion/description/

将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
解释：https://leetcode.com/problems/zigzag-conversion/discuss/3435/If-you-are-confused-with-zigzag-patterncome-and-see!
*/

/*整体思路是 :	按行根据规律逐个元素写出。
*/
class Solution {
public:
	string convert(string s, int numRows) {
		if (!s.size() || numRows == 1)
			return s;
		string result;
		int length = s.size();
		//处理第一行
		for (int i = 0; i < length;) {
			result += s[i];
			i += 2 * numRows - 2;
		}
		for (int i = 1; i < numRows; ++i) {
			//每一行的元素增量
			int increment = (2 * numRows - 2 - 2 * i);
			for (int j = i; j < length;) {
				result += s[j];
				//注意最后一行要剔除出去
				if (i < numRows - 1 && j + increment < length) {
					result += s[j + increment];
				}
				j += increment + 2 * i;
			}
		}
		return result;
	}
};