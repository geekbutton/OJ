// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
57. ��������
https://leetcode-cn.com/problems/insert-interval/description/


����һ�����ص��� ������������ʼ�˵�����������б�

���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�
����б�Ҫ�Ļ������Ժϲ����䣩��
*/

/*����˼·�� :�Ƚ���Ԫ�ذ�˳����뵽ԭ�����б��У��پ���56��ĺϲ��������⡣
ע������е��������µ��µĵ�����ʧЧ���⡣
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
		//���ȶ�Ԫ�ؽ��в��룬��֤����������б�������
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