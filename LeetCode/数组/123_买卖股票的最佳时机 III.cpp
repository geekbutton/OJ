// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
123. 买卖股票的最佳时机 III
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1


给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

/*整体思路是 :	利用动态规划算法，一个维度为天数，另外一个维度为进行的交易次数。当交易次数为
1时，即为求解习题121.当交易次数为2时，就可以利用交易一次时的结果来求解，其状态转移方程为：
dp[k,i] = max(dp[k,i-1],prices[i]-prices[j]+dp[k-1,j-1],j=[1...i]);
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int num = prices.size();
		if (!num)
			return 0;
		vector<vector<int>> result(2, vector<int>(num));
		int min_price = prices[0];
		//先处理第一行，及交易次数为1时的最大利润
		for (int i = 1; i < num; ++i) {
			min_price = min(min_price, prices[i]);
			result[0][i] = max(result[0][i - 1], prices[i] - min_price);
		}
		//处理第二行，考虑上述状态转移方程则需要时间复杂度为O(n^2)，因为j要从1遍历
		//到i，为了减少时间复杂度进行了如下所示的优化，通过一个min_temp保存了从1
		//i的最小(prices[j]+dp[k-1,j-1)
		int min_temp = prices[0];
		for (int j = 1; j < num; ++j) {
			result[1][j] = max(result[0][j], result[1][j - 1]);
			min_temp = min(min_temp, prices[j] - result[0][j - 1]);
			result[1][j] = max(result[1][j], prices[j] - min_temp);
		}
		return result[1][num - 1];
	}
};