// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
33. ������ת��������
https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/

���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��
����Լ��������в������ظ���Ԫ�ء�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
*/

/*����˼·�� :	���ж��Ƿ�����ת��������û�У��򰴼򵥵Ķ��ֲ��ҽ����������ת����Ҫ�����
���ж��ֲ��ҡ�
*/
int find_index(int, int, vector<int>&, int, int, int);
int simple_find(int, int, vector<int>&, int);
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		int num = nums.size() - 1;
		int left = nums[0], right = nums[num];
		if (target == left)
			return 0;
		if (target == right)
			return num;

		int index = -1;
		int flag = 0;				//�����ж�Ŀ������Ӧ������ת���ǰ�λ��Ǻ�Ρ�
		if (target > left)
			flag = 1;
		if (left >= right)
			index = find_index(0, num, nums, target, num, flag);
		else
			index = simple_find(0, num, nums, target);

		return index;
	}
};

int find_index(int l, int r, vector<int>& nums, int target, int num,int flag) {
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return mid;
	if (l >= r)
		return -1;
	/*���������
		1.	��ǰ�Σ���ʱ�ж��м�ֵ��Ŀ��ֵ���м�ֵ��βֵ��С->���У���С->���У����->����
		2.	�ں�Σ���ʱ�ж��м�ֵ��Ŀ��ֵ���м�ֵ��βֵ����->���ң�С��->���ң�СС->����
	*/
	if (flag) {
		if (target < nums[mid])
			return find_index(l, mid - 1, nums, target, num,  flag);
		if (nums[mid] >= nums[num])
			return find_index(mid + 1, r, nums, target, num, flag);
		return find_index(l, mid - 1, nums, target, num, flag);
	}
	else {
		if (target > nums[mid])
			return find_index(mid + 1, r, nums, target, num, flag);
		if (nums[mid] >= nums[num])
			return find_index(mid + 1, r, nums, target, num, flag);
		return find_index(l, mid - 1, nums, target, num, flag);
	}
}

int simple_find(int l, int r, vector<int>& nums, int target) {
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return mid;
	if (l >= r)
		return -1;
	if (target > nums[mid])
		return simple_find(mid + 1, r, nums, target);
	else
		return simple_find(l, mid - 1, nums, target);
}