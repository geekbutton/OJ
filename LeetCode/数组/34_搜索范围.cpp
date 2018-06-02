// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
34. 搜索范围
https://leetcode-cn.com/problems/search-for-a-range/description/

给定一个按照升序排列的整数数组 nums，和一个目标值 target。
找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
*/

/*整体思路是 :	按照二分查找先找到第一个等于目标值的位置，如没有则返回[-1，-1]。
如有，则以该点作为新的左值和右值，递归寻找该位置左右两边等于目标值的位置。并更新左右位置索引
*/
void find_range(int, int, vector<int>&, vector<int>&, int);
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1,-1 };
		if (nums.size() == 0) {
			return result;
		}
		find_range(0, nums.size() - 1, nums, result, target);
		return result;
	}
};

void find_range(int l, int r, vector<int>& nums, vector<int>& result, int target) {
	int mid = (l + r) / 2;
	if (mid < 0 || mid > nums.size() - 1 || l > r)		//异常退出条件
		return;
	if (nums[mid] == target) {						//找到了目标值
		if (mid < result[0] || result[0] == -1)		//判断更新左值
			result[0] = mid;	
		if (mid > result[1])						//判断更新右值
			result[1] = mid;
		//从该位置左右两边迭代查找
		find_range(l, mid - 1, nums, result, target);	
		find_range(mid + 1, r, nums, result, target);
		return;
	}
	if (l >= r)
		return;
	//普通二分查找过程
	if (target < nums[mid])
		return find_range(l, mid - 1, nums, result, target);
	return find_range(mid + 1, r, nums, result, target);
}