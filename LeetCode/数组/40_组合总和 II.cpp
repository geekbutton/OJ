// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
40. 组合总和 II
https://leetcode-cn.com/problems/combination-sum-ii/description/

给定一个数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。
*/

/*整体思路是 :	根据组合总和题目的解答方式求解符合条件的解，需要注意的是该道题每次需要额外
判断递归的下一个元素是否等于上一个元素，如果等于就跳过，以避免出现重复组合。
*/
void Get_result(vector<int>&, vector<vector<int>>&, vector<int>&, int, int&, int);
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> iv;
		sort(candidates.begin(), candidates.end());
		int sum = 0;
		Get_result(candidates, result, iv, target, sum, 0);
		return result;
	}
};

//递归来解决
void Get_result(vector<int>& candidates, vector<vector<int>>& result, vector<int>& iv,
	int target, int& sum, int level) {
	int num = candidates.size();
	if (sum < target) {
		for (int i = level; i < num; ++i) {
			if (i > level && candidates[i] == candidates[i - 1])
				continue;
			//小于的情况，可以继续向里面填入数字
			if (candidates[i] < target - sum) {
				iv.push_back(candidates[i]);
				sum += candidates[i];
				Get_result(candidates, result, iv, target, sum, i + 1);
				iv.pop_back();					//迭代结束后删除最后一个元素，继续从下一个位置开始计算
				sum -= candidates[i];			//这样就可以实现逐层遍历
				continue;
			}
			//等于的情况，添加该元素，添加对应vector，退出前删除最后一个元素
			else if (candidates[i] == target - sum) {
				iv.push_back(candidates[i]);
				result.push_back(iv);
				iv.pop_back();
				return;
			}
			else {
				return;
			}
		}
	}
}