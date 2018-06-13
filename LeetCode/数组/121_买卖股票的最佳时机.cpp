// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
121. 买卖股票的最佳时机
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），
设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。
*/

/*整体思路是 :	两种解决思路，第一种保存两个数组，一个表示从位置0到位置i的最小值，一个表示
从尾位置到i的最大值，之后两个数组对应元素相减再遍历即可得到最大利润。该方法时间复杂度为O(n)，
空间复杂度为O(n)。
第二种思路是从0位置开始遍历元素，每遍历一个元素更新最小price，同时计算当前price-最小price的
值并更新最大利润。该算法时间复杂度为O(n)空间复杂度为O(1)。注意理解之所以用当前price-最小是因为
卖出操作一定在买入操作后面。
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int num = prices.size();
		if (!num)
			return 0;
		vector<int> max_range = prices, min_range;
		int max_value = 0, min_value = prices[0];
		//获得索引对应最小值数组
		for (int i = 0; i < num; ++i) {
			if (prices[i] < min_value) {
				min_value = prices[i];
			}
			min_range.push_back(min_value);
		}
		//获得索引对应最大值数组
		for (int i = 0; i < num; ++i) {
			if (prices[num - 1 - i] > max_value)
				max_value = prices[num - 1 - i];
			max_range[num - 1 - i] = max_value;
		}
		int result = 0;
		//两数组相减后遍历即可得到最大利润
		for (int i = 0; i < num; ++i) {
			if (max_range[i] - min_range[i] > result)
				result = max_range[i] - min_range[i];
		}
		return result;
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int num = prices.size();
		if (!num)
			return 0;
		int min_price = prices[0], result = 0;
		//只遍历一次，每次更新最小price和最大利润
		for (int i = 0; i < num; ++i) {
			min_price = min(min_price, prices[i]);
			result = max(result, prices[i] - min_price);
		}
		return result;
	}
};