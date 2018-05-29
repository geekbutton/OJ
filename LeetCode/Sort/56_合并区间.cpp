// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
56. �ϲ�����
https://leetcode-cn.com/problems/merge-intervals/description/


����һ������ļ��ϣ���ϲ������ص������䡣
*/

/*����˼·�� :�Ƚ�ȥ��������Ԫ�ش�С����Ȼ�����αȽϵ�ǰ�����βԪ�غ���һ�����ͷԪ��
�Ĵ�С��ע�⻹Ҫ�Ƚϵ�ǰȥ��βԪ�غ���һ����βԪ�صĴ�С��
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
		//����������ʼ��ͬʱ��ʹ����βԪ��Ϊ�ϴ�ֵ��
		for (auto x : intervals) {
			if (x.end >= im[x.start])
				im[x.start] = x.end;
		}
		vector<Interval> result;
		auto iter = im.begin();
		int start = iter->first;			//��¼����ͷ��βԪ�����ں����Ƚ�
		int end = iter->second;
		for (int i = 0; iter != im.end(); ++iter, ++i) {
			intervals[i] = Interval(iter->first, iter->second);
		}
		auto iter2 = intervals.begin();
		for (iter2; iter2 != intervals.end() - 1;) {
			if (end >= (iter2 + 1)->start) {
				end = (iter2 + 1)->end > end ? (iter2 + 1)->end : end;	//ȷ�����ص�ʱ��ȷ���µ�βԪ��
				iter2 += 1;
				continue;
			}
			//���ص�ʱ���µ��������������С�
			result.push_back(Interval(start, end));
			iter2 += 1;					//ע��iter2�ĸ���ʱ��
			start = iter2->start;
			end = iter2->end;
		}
		result.push_back(Interval(start, end));
		return result;
	}
};