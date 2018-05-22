// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
239. 滑动窗口最大值

https://leetcode-cn.com/problems/sliding-window-maximum/description/

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。
返回滑动窗口最大值。
你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。
*/

/*整体思路是利用双端队列进行处理以保证时间复杂度为O(n)，基本原理是判断新进入的元素，
如果新进入的元素大于队列的尾元素，则将为元素出队，一直到队列的尾元素不小于当前新进入元素，
通过该方法保证队列中的元素为递减序，因此每次的窗口最大值为队列的队头元素。
注意：应该在队列中保存元素所在索引，而非元素，否则在滑动窗口的过程中将无法判断是否应该将
队头出队。
*/
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> id_window;
		vector<int> result;
		if (nums.size() == 0)
			return result;
		for (int i = 0; i < k; ++i) {						//先处理前K个元素
			while (id_window.size()) {
				if (nums[i] > nums[id_window.back()]) {
					id_window.pop_back();
					continue;
				}
				id_window.push_back(i);
				break;
			}
			if(id_window.size()==0)
				id_window.push_back(i);
		}
		result.push_back(nums[id_window.front()]);
		for (int i = k; i < nums.size(); ++i) {
			while (id_window.front() < i - k + 1)
				id_window.pop_front();
			while (id_window.size()) {
				if (nums[i] > nums[id_window.back()]) {
					id_window.pop_back();
					continue;
				}
				id_window.push_back(i);
				break;
			}
			if (id_window.size() == 0)
				id_window.push_back(i);
			result.push_back(nums[id_window.front()]);
		}
		return result;
	}
};
