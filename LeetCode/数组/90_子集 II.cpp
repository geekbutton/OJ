// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
90. �Ӽ� II
https://leetcode-cn.com/problems/subsets-ii/description/

����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
*/

/*����˼·�� :	����ϰ��78�Ľⷨ�����������ڱ����д����ظ�Ԫ�ء�Ϊ����ظ�Ԫ�أ��Ƚ�����
���򡣱������飬�жϵ�ǰԪ��Ӧ�ò��뵽�������ս������Щ�����С������ǰԪ�ز�����ǰһ
Ԫ�أ�������õ�ǰ��������������С����������������ϴβ���Ԫ�ز�������������(��ȷ��������
������Ϊ����һ����ͬ��ֵ���������ϴβ�����ͬ�Ľ��)��
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result{ vector<int>{} };
		if (!nums.size())
			return result;
		sort(nums.begin(), nums.end());			//һ��Ҫ����
		int index = 1;							//��ʾ��ǰԪ�������������ڲ�����Ԫ�غ�ָ����Ԫ�ؿ�ʼλ��
		int num = nums.size();
		result.push_back(vector<int>{nums[0]});		//�Ȳ���ռ�����Ԫ��
		for (int i = 1; i < nums.size(); ++i) {
			//�жϵ�ǰԪ�غ���ǰһ��Ԫ��
			//�����ֻ�ܲ������ϴβ������������У��±��index��ʼ
			if (nums[i] == nums[i - 1]) {
				int r = result.size();
				for (int j = index; j < r; ++j) {
					vector<int> temp = result[j];
					temp.push_back(nums[i]);
					result.push_back(temp);
					++index;		//ÿ����һ��������һ���±�λ��
				}
			}//���򣬲��������������У�ͬʱ��indexΪ����ǰresult��С����ʾ��һ������λ��
			else {
				index = result.size();
				for (int j = 0; j < index; ++j) {
					vector<int> temp = result[j];
					temp.push_back(nums[i]);
					result.push_back(temp);
				}
			}
		}
		return result;
	}
};