// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
524. 通过删除字母匹配到字典里最长单词
https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/

给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，
返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
*/

/*整体思路是先将每一个字符串与给定字符串比较，找出符合条件的串，将符合条件的最长串
传入一个set进行排序，得到字典序下的最长字符串。
*/
bool comp(const string&, const string&);
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		set<string> ss;
		vector<string> sv;
		int max_len = 0;
		for (int i = 0; i < d.size(); ++i) {
			if (d[i].size() >= max_len && comp(s, d[i])) {				//可以提前退出
				if (d[i].size() >= max_len) {				//只插入长度递增的字符串
					sv.push_back(d[i]);
					max_len = d[i].size();
				}
			}
		}
		if (sv.size() == 0)
			return NULL;
		//因为vector中字符串长度递增，所以反序找出最大长度相同的串
		for (auto iter = sv.rbegin(); iter != sv.rend(); ++iter) {	
			if (iter->size() == max_len) {
				ss.insert(*iter);
				continue;
			}
			break;
		}
		return *(ss.begin());

	}
};

//比较字典中的字符串能否通过给定字符串的到(O(n+k))
bool comp(const string& s, const string& d) {
	auto iter_s = s.begin();
	auto iter_d = d.begin();

	for (; iter_s != s.end() && iter_d != d.end();) {
		if (*iter_s != *iter_d) {
			++iter_s;
			continue;
		}
		++iter_s;
		++iter_d;
	}

	if (iter_d != d.end())
		return false;
	return true;
}