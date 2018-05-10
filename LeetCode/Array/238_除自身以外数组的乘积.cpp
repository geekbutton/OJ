// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
238. 除自身以外数组的乘积

https://leetcode-cn.com/problems/product-of-array-except-self/description/
*/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> iv_prev(nums.size(),1), iv_next(nums.size(),1);
		int mul_prev = 1, mul_next = 1;
		int num = nums.size();
		for (int i = 1; i < num; ++i) {
			mul_prev *= nums[i - 1];
			iv_prev[i] = mul_prev;
			mul_next *= nums[num - i];
			iv_next[num - i - 1] = mul_next;
		}
		vector<int> result;
		for (int i = 0; i < num; ++i) {
			result.push_back(iv_prev[i] * iv_next[i]);
		}
		return result;
	}
};

