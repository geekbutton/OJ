// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
274. H指数
https://leetcode-cn.com/problems/h-index/description/

给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。

h指数的定义: “一位有 h 指数的学者，代表他（她）的 N 篇论文中至多有 h 篇论文，
分别被引用了至少 h 次，其余的 N - h 篇论文每篇被引用次数不多于 h 次。"
*/

/*整体思路是 :	先将引用次数从小到大排序，然后将引用次数依次和当前剩余论文数比较，
当且仅当当前引用次数大于等于剩余引用次数时，符合H指数的定义。返回第一个满足该条件的值
即为H指数。
*/
class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int num = citations.size();
		for (int i = 0; i < citations.size(); ++i) {
			if (citations[i] >= num - i)
				return num - i;			//因为剩余论文数逐渐减少，所以第一满足条件的H值即为最大H指数
		}
		return 0;
	}
};