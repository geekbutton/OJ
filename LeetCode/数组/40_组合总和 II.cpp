// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
40. ����ܺ� II
https://leetcode-cn.com/problems/combination-sum-ii/description/

����һ������ candidates ��һ��Ŀ���� target ��
�ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�

˵����
�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ�
*/

/*����˼·�� :	��������ܺ���Ŀ�Ľ��ʽ�����������Ľ⣬��Ҫע����Ǹõ���ÿ����Ҫ����
�жϵݹ����һ��Ԫ���Ƿ������һ��Ԫ�أ�������ھ��������Ա�������ظ���ϡ�
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

//�ݹ������
void Get_result(vector<int>& candidates, vector<vector<int>>& result, vector<int>& iv,
	int target, int& sum, int level) {
	int num = candidates.size();
	if (sum < target) {
		for (int i = level; i < num; ++i) {
			if (i > level && candidates[i] == candidates[i - 1])
				continue;
			//С�ڵ���������Լ�����������������
			if (candidates[i] < target - sum) {
				iv.push_back(candidates[i]);
				sum += candidates[i];
				Get_result(candidates, result, iv, target, sum, i + 1);
				iv.pop_back();					//����������ɾ�����һ��Ԫ�أ���������һ��λ�ÿ�ʼ����
				sum -= candidates[i];			//�����Ϳ���ʵ��������
				continue;
			}
			//���ڵ��������Ӹ�Ԫ�أ���Ӷ�Ӧvector���˳�ǰɾ�����һ��Ԫ��
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