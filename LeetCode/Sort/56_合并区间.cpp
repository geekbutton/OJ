// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
56. 合并区间
https://leetcode-cn.com/problems/merge-intervals/description/


给出一个区间的集合，请合并所有重叠的区间。
*/

/*整体思路是 :先将去减按照首元素大小排序，然后依次比较当前区间的尾元素和下一区间的头元素
的大小，注意还要比较当前去减尾元素和下一区间尾元素的大小。
*/
/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return intervals;
		
		map<int, int> im;
		//处理当区间起始相同时，使区间尾元素为较大值。
		for (auto x : intervals) {
			if (x.end >= im[x.start])
				im[x.start] = x.end;
		}
		vector<Interval> result;
		auto iter = im.begin();
		int start = iter->first;			//记录区间头和尾元素用于后续比较
		int end = iter->second;
		for (int i = 0; iter != im.end(); ++iter, ++i) {
			intervals[i] = Interval(iter->first, iter->second);
		}
		auto iter2 = intervals.begin();
		for (iter2; iter2 != intervals.end() - 1;) {
			if (end >= (iter2 + 1)->start) {
				end = (iter2 + 1)->end > end ? (iter2 + 1)->end : end;	//确定有重叠时，确定新的尾元素
				iter2 += 1;
				continue;
			}
			//不重叠时将新的区间更新至结果中。
			result.push_back(Interval(start, end));
			iter2 += 1;					//注意iter2的更新时机
			start = iter2->start;
			end = iter2->end;
		}
		result.push_back(Interval(start, end));
		return result;
	}
};