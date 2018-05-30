// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
179. 最大数
https://leetcode-cn.com/problems/largest-number/description/


给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
*/

/*整体思路是 :	定义一个compare函数，指定一个规则，判断两个字符串在两种顺序下的大小，按此
排序，待所有排序完成后从后往前将字符串累加即可得最终结果。
注意其变形求最小数，思考如何完成(理论上修改comp判断条件即可)。
*/
bool comp(string s1, string s2);
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> sv;
		string result;
		for (auto x : nums) {
			sv.push_back(to_string(x));
		}
		sort(sv.begin(), sv.end(),comp);
		for (auto iter = sv.rbegin(); iter != sv.rend(); ++iter) {
			result += *iter;
		}
		int i = 0;
		//处理全0的状况。
		while (result[i] == '0' && i < result.size() - 1) {
			++i;
		}
		result = result.substr(i);
		return result;
		
	}
};
//自定义比较函数，仍是由小到大排列也可以反序
bool comp(string s1, string s2) {
	return s1 + s2 < s2 + s1;
}