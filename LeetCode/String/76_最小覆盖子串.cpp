// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
76. 最小覆盖子串
https://leetcode-cn.com/problems/minimum-window-substring/description/

给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
*/

/*整体思路是 :	利用一个哈希表map存储t中的每个元素及其出现次数，设置一个计数器表示包含的匹配
字符数。然后遍历s，每次当s[i]出现在t中时，就在map中对其计数减1，同时当其计数大于等于0时，对
count加1，如count等于t.size()则表示当前字符串可以匹配T，更新最小子串。然后移动子串左指针，直到
子串不能包含T中所有元素，此时保持左指针更新右指针。重复这个过程。
*/
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> tm;
		//建立map，对T中元素计数
		for (int i = 0; i < t.size(); ++i)
			++tm[t[i]];
		int count = 0;					//当前包含匹配字符数
		int l = 0, r = 0, min_len = s.size() + 1;		//标记左右位置及最小子串长度
		string result;
		for (r; r < s.size(); ++r) {
			if (tm.find(s[r]) != tm.end()) {		//在s中找到T中的元素则对应计数减1
				tm[s[r]]--;
				if (tm[s[r]] >= 0)			//注意，只有在引用计数大于等于0时，count才加1，
					++count;				//表示带包含字符的增加
			}
			while (count == t.size()) {
				if (r - l + 1 < min_len) {		//更新最小子串
					min_len = r - l + 1;
					result = s.substr(l, min_len);
				}
				if (tm.find(s[l]) != tm.end()) {	
					tm[s[l]]++;			//如果子串最左边元素在T中，则对应引用计数加1
					if (tm[s[l]] > 0)	//注意，只有当引用计数大于0时，才改变count
						--count;		//因为若其小于0，则当前子串仍然包含大于T中元素的元素
				}
				++l;					//更新左指针
			}

		}
		return result;
	}
};