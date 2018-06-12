// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
90. 子集 II
https://leetcode-cn.com/problems/subsets-ii/description/

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
*/

/*整体思路是 :	类似习题78的解法，但区别在于本题中存在重复元素。为解决重复元素，先将数组
排序。遍历数组，判断当前元素应该插入到现有最终结果的哪些数组中。如果当前元素不等于前一
元素，则插入置当前结果的所有数组中。若相等则仅插入至上次插入元素产生的新数组中(以确保旧数组
不会因为插入一个相同的值而产生和上次插入相同的结果)。
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result{ vector<int>{} };
		if (!nums.size())
			return result;
		sort(nums.begin(), nums.end());			//一定要排序
		int index = 1;							//表示当前元素索引，用于在插入新元素后指定新元素开始位置
		int num = nums.size();
		result.push_back(vector<int>{nums[0]});		//先插入空集和首元素
		for (int i = 1; i < nums.size(); ++i) {
			//判断当前元素和其前一个元素
			//相等则只能插入至上次产生的新数组中，下标从index开始
			if (nums[i] == nums[i - 1]) {
				int r = result.size();
				for (int j = index; j < r; ++j) {
					vector<int> temp = result[j];
					temp.push_back(nums[i]);
					result.push_back(temp);
					++index;		//每插入一个，更新一次下标位置
				}
			}//否则，插入至所有数组中，同时置index为插入前result大小，表示下一个插入位置
			else {
				index = result.size();
				for (int j = 0; j < index; ++j) {
					vector<int> temp = result[j];
					temp.push_back(nums[i]);
					result.push_back(temp);
				}
			}
		}
		return result;
	}
};