// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
122. ������Ʊ�����ʱ�� II
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/


����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
*/

/*����˼·�� :	��Ŀ���󣬽��Ҳ����ȷ��
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (!prices.size())
			return 0;
		int result = 0, min_price = prices[0];
		for (int i = 0; i < prices.size(); ++i) {
			min_price = min(min_price, prices[i]);
			result = max(result, prices[i] - min_price);
		}
		int result_2 = 0;
		for (int i = 0; i < prices.size() - 1; ++i) {
			if (prices[i] < prices[i + 1]) {
				result_2 += (prices[i + 1] - prices[i]);
			}
		}
		return max(result, result_2);
	}
};