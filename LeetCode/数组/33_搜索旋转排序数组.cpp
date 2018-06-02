// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
33. 搜索旋转排序数组
https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
*/

/*整体思路是 :	先判断是否有旋转发生，如没有，则按简单的二分查找解决。若有旋转就需要分情况
进行二分查找。
*/
int find_index(int, int, vector<int>&, int, int, int);
int simple_find(int, int, vector<int>&, int);
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		int num = nums.size() - 1;
		int left = nums[0], right = nums[num];
		if (target == left)
			return 0;
		if (target == right)
			return num;

		int index = -1;
		int flag = 0;				//用来判断目标数据应该在旋转后的前段还是后段。
		if (target > left)
			flag = 1;
		if (left >= right)
			index = find_index(0, num, nums, target, num, flag);
		else
			index = simple_find(0, num, nums, target);

		return index;
	}
};

int find_index(int l, int r, vector<int>& nums, int target, int num,int flag) {
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return mid;
	if (l >= r)
		return -1;
	/*两种情况：
		1.	在前段，此时判断中间值与目标值，中间值与尾值：小->左中，大小->左中，大大->中右
		2.	在后段，此时判断中间值与目标值，中间值与尾值：大->中右，小大->中右，小小->左中
	*/
	if (flag) {
		if (target < nums[mid])
			return find_index(l, mid - 1, nums, target, num,  flag);
		if (nums[mid] >= nums[num])
			return find_index(mid + 1, r, nums, target, num, flag);
		return find_index(l, mid - 1, nums, target, num, flag);
	}
	else {
		if (target > nums[mid])
			return find_index(mid + 1, r, nums, target, num, flag);
		if (nums[mid] >= nums[num])
			return find_index(mid + 1, r, nums, target, num, flag);
		return find_index(l, mid - 1, nums, target, num, flag);
	}
}

int simple_find(int l, int r, vector<int>& nums, int target) {
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return mid;
	if (l >= r)
		return -1;
	if (target > nums[mid])
		return simple_find(mid + 1, r, nums, target);
	else
		return simple_find(l, mid - 1, nums, target);
}