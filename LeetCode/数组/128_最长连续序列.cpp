// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
128. 最长连续序列
https://leetcode-cn.com/problems/longest-consecutive-sequence/description/

给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
*/

/*整体思路是 :	一个简单的想法是对数组进行排序，然后顺序遍历更新最大连续子序列的长度。但是
排序的时间复杂度高于O(n)。因此，在本题中，我们采用哈希表的方式来进行查找，因为其可以实现O(1)的
查找时间。对于每个数，我们顺序查找比它大1的值和比它小1的值，同时为了节省时间，设置一个计数值
count，count等于数组大小，这样可以保证程序最多只会查找count个数。
*/
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> is;
		for (auto x : nums)
			is.insert(x);
		int count = nums.size();
		int result = 0, value = 0;
		//注意此处的判断退出条件和更新，理解为什么count不会对每个i都从最大值开始计数。
		//因为假如对nums[i]检测到了x个连续的数，则若nums[i+1]也在此连续序列中，则最终结果
		//也是x；若num[i+1]不在此连续序列中，则其最大连续序列为count-x
		for (int i = 0; i < nums.size() && count; ++i, --count) {
			value = nums[i];
			int temp_result = 1;		//存储nums[i]对应最大连续序列，从1开始因为包含自身
			while (count) {
				//先向递增1的方向查找
				if (is.find(value + 1) != is.end()) {
					++temp_result;
					++value;
					--count;
					continue;
				}
				break;
			}
			//再向递减1的方向查找
			value = nums[i];
			while (count) {
				if (is.find(value - 1) != is.end()) {
					++temp_result;
					--value;
					--count;
					continue;
				}
				break;
			}
			//查找完成后，更新result的值
			result = max(result, temp_result);
		}
		return result;
	}
};