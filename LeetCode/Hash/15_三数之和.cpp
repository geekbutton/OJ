// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
15. 三数之和
https://leetcode-cn.com/problems/3sum/description/

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

/*整体思路是 :	首先想的是利用二数之和的方法，遍历每一个元素nums[i]，则在其右侧区间利用两数之和找到
和等于-nums[i]找到对应元素，难点在于怎么去除重复元素。第二种方式是在求两数之和时利用两个指针进行
夹逼，同时去掉不可能的情况以减少时间开销。注意，这两种方法都需要对原始数据进行排序，以便于去除重复元素。
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return vector<vector<int>>{};
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());	//首先排序
		for (int i = 0; i < nums.size() - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1])	//对于重复出现的元素直接跳过不再处理
				continue;
			//设置元素右侧区域进行夹逼
			int l = i + 1, r = nums.size() - 1, value = -nums[i];
			for (; l < r;) {
				//首先跳过重复元素
				if (l > i + 1 && nums[l] == nums[l - 1]) {
					++l; continue;
				}
				if (r < nums.size() - 1 && nums[r] == nums[r + 1]) {
					--r; continue;
				}
				//跳过不可能满足条件的值，即必大于或必小于指定值的情况
				if (nums[l] + nums[l + 1] > value || nums[r] + nums[r - 1] < value)
					break;
				//满足条件则添加至结果
				if (nums[l] + nums[r] == value) {
					result.push_back(vector<int>{nums[i], nums[l], nums[r]});
					++l; --r;
				}
				//大于则将右侧指针右移
				else if (nums[l] + nums[r] > value) {
					--r;
					continue;
				}//小于则将左侧指针左移
				else if (nums[l] + nums[r] < value)
					++l;
			}
		}
		return result;
	}
};