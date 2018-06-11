// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
81. ������ת�������� II
https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/

���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,0,1,2,2,5,6] ���ܱ�Ϊ [2,5,6,0,0,1,2] )��
��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false��
*/

/*����˼·�� :	����33�⣬�������������п��ܴ����ظ�Ԫ�ء������ö��ֲ���ʱ���������ͷβԪ��
����ҵ����м�Ԫ�أ����ʱ�޷��жϲ��ҵ�Ԫ��Ӧ�����Ǹ������ڡ�Ϊ���������⣬���ж�����ͷβ
Ԫ���Ƿ���ȣ���βָ���ƶ�����һ������������ͷԪ�ص�λ�ã��ٰ���33��ⷨ���ɵõ���ȷ�����
*/
bool simple_bs(int, int, vector<int>&, int);
bool bs(int, int, vector<int>&, int);
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (!nums.size())
			return false;
		int num = nums.size();
		int flag = 0;
		bool result;
		//�ƶ�βָ������һ����������Ԫ�ص�λ�ô�
		while (num > 1 && nums[0] == nums[num - 1])
			--num;
		if (target == nums[0] || target == nums[num - 1])
			return true;
		//��Ԫ��С��βԪ�أ����ռ򵥵Ķ��ֲ��Ҵ���
		if (nums[0] < nums[num - 1])
			return simple_bs(0, num - 1, nums, target);
		//���򣬰���33��ⷨ����
		return bs(0, num - 1, nums, target);
	}
};

bool simple_bs(int l, int r, vector<int>& nums, int target) {
	if (l > r)
		return false;
	int mid = (l + r) / 2;
	if (nums[mid] == target)
		return target;
	if (nums[mid] < target)
		return simple_bs(mid + 1, r, nums, target);
	if (nums[mid] > target)
		return simple_bs(l, mid - 1, nums, target);
}

bool bs(int l, int r, vector<int>& nums,int target) {
	//�ֳ��������ȷ���ݹ��������
	if (l > r)
		return false;
	int mid = (l + r) / 2;
	if (nums[mid] == target || nums[l] == target || nums[r] == target)
		return true;
	if (target > nums[mid]) {
		//ע�⣡����ʼ���Ǹ�������Ԫ�رȽϣ������Ǹ���ǰ���ҷ�Χ����Ԫ�رȽϣ�����
		if (nums[mid] < nums[0] && target >= nums[0])
			return bs(l, mid - 1, nums, target);
		return bs(mid + 1, r, nums, target);
	}
	else {
		if (nums[mid] >= nums[0] && target <= nums[0])
			return bs(mid + 1, r, nums, target);
		return bs(l, mid - 1, nums, target);
	}
}