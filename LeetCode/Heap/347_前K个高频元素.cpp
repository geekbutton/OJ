// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
347. 前K个高频元素

https://leetcode-cn.com/problems/top-k-frequent-elements/description/

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*/

/*主要思路：利用堆排序获得前K个最大的元素，注意应使用无序map以保证时间复杂度
*/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> result;
		unordered_map<int, int> im;
		for (auto v : nums)
			++im[v];
		priority_queue<pair<int, int>> iq;
		for (auto iter : im)
			iq.push({ iter.second,iter.first });		//注意堆对应map元素交换
		int n = 0;
		while (n != k) {
			result.push_back(iq.top().second);
			iq.pop();
			++n;
		}
		return result;
	}
};
