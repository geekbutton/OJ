// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
45. ��Ծ��Ϸ II
https://leetcode-cn.com/problems/jump-game-ii/description/

����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
���������ǿ��Ե�����������һ��λ�á�
*/

/*����˼·�� :	����̰���㷨��ÿ��ѡ�������һ���ܴﵽ�ĵط���Զ�ĵ㡣
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int count = 0;
		int current = 0, l = 0, num = nums.size();
		for (current; current < num - 1;) {
			int value = nums[current];
			int max_index = current + 1;				//��Զ�ĵ������
			if (current + nums[current] >= num - 1)
				return ++count;
			for (l = current + 1; l <= current + value; ++l) {
				//�ҳ���һ���ܴﵽ��Զ�ط��ĵ�
				if (nums[l] + l >= nums[max_index] + max_index) {
					max_index = l;
				}
			}
			++count;
			current = max_index;
		}
		return count;
	}
};