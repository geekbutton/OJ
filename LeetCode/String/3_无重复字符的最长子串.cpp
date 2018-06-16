// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
3. 无重复字符的最长子串
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/

给定一个字符串，找出不含有重复字符的最长子串的长度。(指的是连续字符串)
*/

/*整体思路是 :	从头开始遍历，建立一个无序set，每次插入元素前判断该元素是否存在， 不存在则直接
插入，否则从指定头位置开始遍历删除直到删除掉重复元素第一次出现的位置。
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0, temp_result = 0;
		int l = 0, r = 0;				//位置索引，索引当前子串的左右位置，用于更新子串
		unordered_set<int> is;			//建立一个无序set用来查找是否存在重复元素
		for (int i = 0; i < s.size(); ++i) {
			if (is.empty()) {
				is.insert(s[i]);
				temp_result = 1;
				continue;
			}//不存在重复元素则直接插入
			if (is.find(s[i]) == is.end()) {
				is.insert(s[i]);
				++temp_result;
				continue;
			}
			//存在重复元素则遍历当前子串查找重复元素，并将路径上的所有元素删除
			r = i;
			result = max(result, temp_result);			//出现重复元素则更新result
			for (l; l < r; ++l) {
				if (s[l] != s[i]) {
					is.erase(s[l]);
					continue;
				}
				temp_result = r - l;
				++l;
				++r;
				break;
			}
		}
		return max(result, temp_result);			//注意，退出循环后最后还要更新一次result
	}
};