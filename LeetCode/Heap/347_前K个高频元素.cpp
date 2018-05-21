// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
347. 前K个高频元素

https://leetcode-cn.com/problems/top-k-frequent-elements/description/

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
*/
/*整体思路是先求得数组中元素出现的频率，再将频率构成堆，从而可以获得前K个最高频率
*/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> result;
		map<int, int> nm;
		for (int i = 0; i < nums.size(); ++i) {						//利用map记录元素及其出现频率
			++nm[nums[i]];
		}
		priority_queue<int> iq;
		for (auto iter = nm.begin(); iter != nm.end(); ++iter) {	//利用频率建堆
			iq.push(iter->second);
		}
		int num = nm.size();
		while (iq.size() > num - k) {				//弹出前K个最大的频率
			int value = iq.top();
			iq.pop();
			for (auto iter = nm.begin(); iter != nm.end(); ++iter) {
				if (iter->second == value)
				{
					result.push_back(iter->first);
					nm.erase(iter);				//注意删除已经选择的元素
					break;
				}
			}
		}
		return result;
	}
};
