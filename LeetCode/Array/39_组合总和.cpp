// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
39.组合总和

https://leetcode-cn.com/problems/combination-sum/description/
*/

void getsolution(vector<int>&, vector<vector<int>>&, vector<int>&, int&, int, int);
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> iv;
		sort(candidates.begin(), candidates.end());
		int sum = 0;
		int level = 0;
		getsolution(candidates,result,iv,sum,target,level);
		
		return result;
	}
};

void getsolution(vector<int>& candidates,vector<vector<int>>& result, vector<int>& iv, int& sum, int target, int level) {
	if (sum < target) {
		for (int i = level; i < candidates.size(); ++i) {
			iv.push_back(candidates[i]);
			sum += candidates[i];
			if (sum > target) {
				iv.pop_back();
				sum -= candidates[i];
				return;
			}
			getsolution(candidates, result, iv, sum, target, i);
			iv.pop_back();
			sum -= candidates[i];
		}
	}
	else if (sum == target) {
		result.push_back(iv);
		return;
	}
}
