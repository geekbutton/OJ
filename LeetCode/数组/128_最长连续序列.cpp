// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
128. ���������
https://leetcode-cn.com/problems/longest-consecutive-sequence/description/

����һ��δ������������飬�ҳ���������еĳ��ȡ�
Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��
*/

/*����˼·�� :	һ���򵥵��뷨�Ƕ������������Ȼ��˳���������������������еĳ��ȡ�����
�����ʱ�临�Ӷȸ���O(n)����ˣ��ڱ����У����ǲ��ù�ϣ��ķ�ʽ�����в��ң���Ϊ�����ʵ��O(1)��
����ʱ�䡣����ÿ����������˳����ұ�����1��ֵ�ͱ���С1��ֵ��ͬʱΪ�˽�ʡʱ�䣬����һ������ֵ
count��count���������С���������Ա�֤�������ֻ�����count������
*/
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> is;
		for (auto x : nums)
			is.insert(x);
		int count = nums.size();
		int result = 0, value = 0;
		//ע��˴����ж��˳������͸��£����Ϊʲôcount�����ÿ��i�������ֵ��ʼ������
		//��Ϊ�����nums[i]��⵽��x����������������nums[i+1]Ҳ�ڴ����������У������ս��
		//Ҳ��x����num[i+1]���ڴ����������У����������������Ϊcount-x
		for (int i = 0; i < nums.size() && count; ++i, --count) {
			value = nums[i];
			int temp_result = 1;		//�洢nums[i]��Ӧ����������У���1��ʼ��Ϊ��������
			while (count) {
				//�������1�ķ������
				if (is.find(value + 1) != is.end()) {
					++temp_result;
					++value;
					--count;
					continue;
				}
				break;
			}
			//����ݼ�1�ķ������
			value = nums[i];
			while (count) {
				if (is.find(value - 1) != is.end()) {
					++temp_result;
					--value;
					--count;
					continue;
				}
				break;
			}
			//������ɺ󣬸���result��ֵ
			result = max(result, temp_result);
		}
		return result;
	}
};