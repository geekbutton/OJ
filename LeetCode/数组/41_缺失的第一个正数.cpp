// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
41. ȱʧ�ĵ�һ������
https://leetcode-cn.com/problems/first-missing-positive/description/

����һ��δ������������飬�ҳ�����û�г��ֵ���С����������
����㷨��ʱ�临�Ӷ�ӦΪO(n)������ֻ��ʹ�ó�������Ŀռ䡣
*/

/*����˼·�� :	������ɵã�δ���ֵ���С������Ӧ���ڷ�Χ[1��n+1]֮�䣬��˶������е�����Ԫ��
���·��ã�����⵽0<n[i]<n+1ʱ,������λ��n[i]����Ԫ�ؽ���(��Ԫ��1��n[0]������ʹ��λ��n[0]��)(��ֵ�ͳ�����Χ�Ĳ�����������λ��ֵ
���ڸ�λ��������1�ģ�������)����ɺ����±������飬��һ��ֵ����Ӧ��Ԫ�ؼ�Ϊȱʧ����С��������
��Ҫע���������+1���ڸ�������Ӧ�÷��õ�ֵ��
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0)
			return 1;
		int result = 0;
		for (int i = 0; i < nums.size(); ++i) {
			//�����������ֵ�Ѿ���Ӧ�ˣ������轻����ֱ�Ӵ�����һ��
			if (nums[i] == i + 1)
				continue;
			//ע��������ж�������ֻ������1-n��Χ��Ԫ�أ��Ҳ���������ȷ��ŵ�λ�õ�����
			if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] -1] != nums[i]) {
				swap(nums[nums[i] - 1], nums[i]);
				--i;
			}
		}
		int i = 0;
		for (i; i < nums.size(); ++i) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return i + 1;
	}
};