// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
53. ��������
https://leetcode-cn.com/problems/maximum-subarray/description/

����һ���������� nums ���ҵ�һ���������͵����������飨������
���ٰ���һ��Ԫ�أ������������͡�
������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/

/*����˼·�� :	���ҵ���һ������0��������ʼ����ͣ����ҵĹ����У����ָ��µ�ǰ���ֵ��
��Ҫ�ӵ�������0����ֱ����Ӳ��Ƚϸ������ֵ����С��0���жϼ�֮����Ƿ����0����������ӣ�
�������0�����¿�ʼ��������顣ע����������ֵһֱ�ڸ��¡����㷨���Ӷ�ΪO(n)��
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int i = 0, max = nums[0];
		for (; i < nums.size(); ++i) {
			if (nums[i] <= 0) {
				if (nums[i] > max)
					max = nums[i];
				continue;
			}
			break;
		}
		int sum = 0;
		for (i; i < nums.size(); ++i) {
			if (nums[i] >= 0) {
				sum += nums[i];
				if (sum > max)
					max = sum;
				continue;
			}
			sum = (sum + nums[i]) > 0 ? (sum + nums[i]) : 0;
			
		}
		return max;
	}
};