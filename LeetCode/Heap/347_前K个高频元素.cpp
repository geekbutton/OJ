// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
347. ǰK����ƵԪ��

https://leetcode-cn.com/problems/top-k-frequent-elements/description/

����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
*/
/*����˼·�������������Ԫ�س��ֵ�Ƶ�ʣ��ٽ�Ƶ�ʹ��ɶѣ��Ӷ����Ի��ǰK�����Ƶ��
*/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> result;
		map<int, int> nm;
		for (int i = 0; i < nums.size(); ++i) {						//����map��¼Ԫ�ؼ������Ƶ��
			++nm[nums[i]];
		}
		priority_queue<int> iq;
		for (auto iter = nm.begin(); iter != nm.end(); ++iter) {	//����Ƶ�ʽ���
			iq.push(iter->second);
		}
		int num = nm.size();
		while (iq.size() > num - k) {				//����ǰK������Ƶ��
			int value = iq.top();
			iq.pop();
			for (auto iter = nm.begin(); iter != nm.end(); ++iter) {
				if (iter->second == value)
				{
					result.push_back(iter->first);
					nm.erase(iter);				//ע��ɾ���Ѿ�ѡ���Ԫ��
					break;
				}
			}
		}
		return result;
	}
};
