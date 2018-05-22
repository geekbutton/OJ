// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
502. IPO

https://leetcode-cn.com/problems/ipo/description/

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*/
/*主要思路是将成本和利润按照配对组成有序map，根据成本和当前资金决定将哪些数据推入堆中
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
			auto iter = im.upper_bound(W);					//确定可推入堆中的数据
			if (iter == im.begin())
				break;
			for (pre_iter; pre_iter != iter; ++pre_iter) {	//推入符合要求的数据
				iq.push(pre_iter->second);
			}
			fianl_capital += iq.top();					//更新最终的利润
			W += iq.top();
			iq.pop();
		}
		return fianl_capital;
	}
};
