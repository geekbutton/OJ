// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
34. ������Χ
https://leetcode-cn.com/problems/search-for-a-range/description/

����һ�������������е��������� nums����һ��Ŀ��ֵ target��
�ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
��������в�����Ŀ��ֵ������ [-1, -1]��
*/

/*����˼·�� :	���ն��ֲ������ҵ���һ������Ŀ��ֵ��λ�ã���û���򷵻�[-1��-1]��
���У����Ըõ���Ϊ�µ���ֵ����ֵ���ݹ�Ѱ�Ҹ�λ���������ߵ���Ŀ��ֵ��λ�á�����������λ������
*/
void find_range(int, int, vector<int>&, vector<int>&, int);
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1,-1 };
		if (nums.size() == 0) {
			return result;
		}
		find_range(0, nums.size() - 1, nums, result, target);
		return result;
	}
};

void find_range(int l, int r, vector<int>& nums, vector<int>& result, int target) {
	int mid = (l + r) / 2;
	if (mid < 0 || mid > nums.size() - 1 || l > r)		//�쳣�˳�����
		return;
	if (nums[mid] == target) {						//�ҵ���Ŀ��ֵ
		if (mid < result[0] || result[0] == -1)		//�жϸ�����ֵ
			result[0] = mid;	
		if (mid > result[1])						//�жϸ�����ֵ
			result[1] = mid;
		//�Ӹ�λ���������ߵ�������
		find_range(l, mid - 1, nums, result, target);	
		find_range(mid + 1, r, nums, result, target);
		return;
	}
	if (l >= r)
		return;
	//��ͨ���ֲ��ҹ���
	if (target < nums[mid])
		return find_range(l, mid - 1, nums, result, target);
	return find_range(mid + 1, r, nums, result, target);
}