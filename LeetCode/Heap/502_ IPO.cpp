// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
502. IPO

https://leetcode-cn.com/problems/ipo/description/

����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
����㷨��ʱ�临�Ӷȱ������� O(n log n) , n ������Ĵ�С��
*/
/*��Ҫ˼·�ǽ��ɱ�������������������map�����ݳɱ��͵�ǰ�ʽ��������Щ�����������
*/

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		int fianl_capital = W;
		multimap<int, int> im;
		for (int i = 0; i < Profits.size(); ++i) {
			im.insert(pair<int, int>(Capital[i], Profits[i]));
		}
		priority_queue<int> iq;
		auto pre_iter = im.begin();
		k = k > Profits.size() ? Profits.size() : k;
		while (k--) {
			auto iter = im.upper_bound(W);					//ȷ����������е�����
			if (iter == im.begin())
				break;
			for (pre_iter; pre_iter != iter; ++pre_iter) {	//�������Ҫ�������
				iq.push(pre_iter->second);
			}
			fianl_capital += iq.top();					//�������յ�����
			W += iq.top();
			iq.pop();
		}
		return fianl_capital;
	}
};
