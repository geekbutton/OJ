// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
57. 插入区间
https://leetcode-cn.com/problems/insert-interval/description/


给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠
如果有必要的话，可以合并区间）。
*/

/*整体思路是 :先将新元素按顺序插入到原区间列表中，再就是56题的合并区间问题。
注意过程中迭代器更新导致的迭代器失效问题。
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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		if (intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		int value = newInterval.start;
		//首先对元素进行插入，保证插入后区间列表仍有序
		auto iter = intervals.begin();
		if (value < intervals[0].start) {
			intervals.insert(iter, newInterval);
			iter = intervals.begin();
		}
		for (; iter != intervals.end() - 1;) {
			if (value >= iter->start&& value >= (iter + 1)->start) {
				++iter;
				continue;
			}
			intervals.insert(++iter, newInterval);
			break;
		}
		if (iter == intervals.end() - 1)
			intervals.insert(++iter, newInterval);

		int start = intervals[0].start;
		int end = intervals[0].end;
		for (iter = intervals.begin(); iter != intervals.end() - 1;) {
			if (end >= (iter + 1)->start) {
				end = (iter + 1)->end > end ? (iter + 1)->end : end;
				++iter;
				continue;
			}
			result.push_back(Interval(start, end));
			++iter;
			start = iter->start;
			end = iter->end;
		}
		result.push_back(Interval(start, end));

		return result;
	}
};