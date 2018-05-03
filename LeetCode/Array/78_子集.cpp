// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
78. 子集

https://leetcode-cn.com/problems/subsets/description/
*/


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result_iv;
		vector<int> iv;
		result_iv.push_back(iv);
		
		for (int i = 0; i < nums.size(); ++i) {
			int temp_value = nums[i];
			if (i <= 0) {
				vector<int> temp_iv{ temp_value };
				result_iv.push_back(temp_iv);
			}
			else {
				int max_iter = result_iv.size();
				vector<int> temp_iv{ temp_value };
				result_iv.push_back(temp_iv);
				for (int j = 1; j < max_iter; ++j) {
					vector<int> temp_iv1 = result_iv[j];
					temp_iv1.push_back(temp_value);
					result_iv.push_back(temp_iv1);
				}
			}

		}
		return result_iv;
	}
};
