// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
81. 搜索旋转排序数组 II
https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
*/

/*整体思路是 :	类似33题，区别在于数组中可能存在重复元素。当采用二分查找时，如果数组头尾元素
相等且等于中间元素，则此时无法判断查找的元素应落于那个区间内。为解决这个问题，先判断数组头尾
元素是否相等，将尾指针移动至第一个不等于数组头元素的位置，再按照33题解法即可得到正确结果。
*/
bool simple_bs(int, int, vector<int>&, int);
bool bs(int, int, vector<int>&, int);
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (!nums.size())
			return false;
		int num = nums.size();
		int flag = 0;
		bool result;
		//移动尾指针至第一个不等于首元素的位置处
		while (num > 1 && nums[0] == nums[num - 1])
			--num;
		if (target == nums[0] || target == nums[num - 1])
			return true;
		//首元素小于尾元素，则按照简单的二分查找处理
		if (nums[0] < nums[num - 1])
			return simple_bs(0, num - 1, nums, target);
		//否则，按照33题解法处理
		return bs(0, num - 1, nums, target);
	}
};

bool simple_bs(int l, int r, vector<int>& nums, int target) {
	if (l > r)
		return false;
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return target;
	if (nums[mid] < target)
		return simple_bs(mid + 1, r, nums, target);
	if (nums[mid] > target)
		return simple_bs(l, mid - 1, nums, target);
}

bool bs(int l, int r, vector<int>& nums,int target) {
	//分成四类情况确定递归查找区间
	if (l > r)
		return false;
	int mid = (l + r) / 2;
	if (nums[mid] == target || nums[l] == target || nums[r] == target)
		return true;
	if (target > nums[mid]) {
		//注意！！！始终是跟数组首元素比较，而不是跟当前查找范围的首元素比较！！！
		if (nums[mid] < nums[0] && target >= nums[0])
			return bs(l, mid - 1, nums, target);
		return bs(mid + 1, r, nums, target);
	}
	else {
		if (nums[mid] >= nums[0] && target <= nums[0])
			return bs(mid + 1, r, nums, target);
		return bs(l, mid - 1, nums, target);
	}
}