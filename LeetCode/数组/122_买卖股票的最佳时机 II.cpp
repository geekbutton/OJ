// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
122. 买卖股票的最佳时机 II
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/


给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

/*整体思路是 :	题目有误，解答也不正确。
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