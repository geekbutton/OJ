// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
373. 查找和最小的K对数字

https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/description/

给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。
找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。
*/

/*整体思路是：建立一个优先堆将元素逐顺序添加入其中排序，最终输入前K个，
注意自定义comp函数
*/
class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		
		
		auto comp = [](pair<int, int> a, pair<int, int> b) {		//lambda函数
			return (a.first + a.second) > (b.first + b.second);
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> iq(comp);	//注意这种写法
		for (int i = 0; i < min((int)nums1.size(), k); ++i) {		//利用min函数计算量
			for (int j = 0; j < min((int)nums2.size(), k); ++j) {
				iq.push(pair<int, int>(nums1[i], nums2[j]));
			}
		}
		vector<pair<int, int>> result;
		k = min(nums1.size()*nums2.size(), k);
		while (k--) {
			result.push_back(iq.top());
			iq.pop();
		}
		return result;
	}
};