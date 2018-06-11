// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
80. 删除排序数组中的重复项 II
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/description/

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，
返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

/*整体思路是 :	类似26题，思路还是利用两个指针，一个指向当前带插入位置，一个指向当前
遍历的元素。唯一的不同在于该题每个元素最多可以出现两次，因此需要进行一个额外的判断。
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int p1 = 0, p2 = 0;
		int num = nums.size();
		int count = 0;
		//首先找到第一个可插入的位置，即第一次出现三元素相同时第三个元素的位置
		for (int i = 0; i < num - 2; ++i) {
			if (nums[i] != nums[i + 1] || nums[i + 1] != nums[i + 2]) {
				++count;
				continue;
			}
			p1 = i + 2;
			count += 2;
			break;
		}
		if (!p1)					//p1为0则说明不存在超过三个的重复元素，直接返回
			return num;
		//否则，从p1的位置开始搜索，找到第一个不等于nums[p1]的元素，从该元素开始遍历p2
		for (int i = p1; i < num; ++i) {
			if (nums[i] == nums[p1])
				continue;
			p2 = i;
			break;
		}
		//p2不为0，则继续遍历，否则直接返回
		if (p2) {
			for (p2; p2 < num - 2; ++p2) {
				//注意元素的插入时机
				//表示在元素最后出现时(也可能是单个元素的第一次出现)，插入一次
				if (nums[p2] != nums[p2 + 1]) {
					nums[p1++] = nums[p2];
					++count;
					continue;
				}
				//表示在元素只剩下两个时，插入一次
				else if (nums[p2 + 1] != nums[p2 + 2]) {
					nums[p1++] = nums[p2 + 1];
					++count;
					continue;
				}
			}
			//插入p2到终点的所有元素，绝对不会使得前面的元素超过两个
			for (--p2; p2 < num; ++p2) {
				nums[p1++] = nums[p2];
				++count;
			}
			return count;
		}
		return count;
	}
};