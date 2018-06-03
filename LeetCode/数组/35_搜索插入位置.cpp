// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
35. ��������λ��
https://leetcode-cn.com/problems/search-insert-position/description/

����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�
*/

/*����˼·�� :	���ն��ֲ������ҵ���һ������Ŀ��ֵ��λ�ã��ؼ��ǵ�û���ҵ�ʱ�Ĵ���
��û���ҵ���ӦԪ�أ��������һ�ε�������l>=r�����ʱ�����жϣ����target���ڴ�ʱΨһ��ֵ
nums[l]���򷵻�����Ϊl+1������Ϊl��
*/
int find_index(int, int, vector<int>&, int);
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		int index = 0;
		index = find_index(0, nums.size() - 1, nums, target);
		return index;
	}
};

int find_index(int l, int r, vector<int>&nums, int target) {
	//ע���ж���������ֻ������Ԫ�ز�������һ����ݹ�ʱ���п��ܳ���l>r�����
	if (l >= r && nums[l] != target) {
		if (target > nums[l])
			return l + 1;		//�����������l+1λ��
		return l;				//С���������lλ��
	}
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return mid;
	if (target > nums[mid])
		return find_index(mid + 1, r, nums, target);
	return find_index(l, mid - 1, nums, target);
}