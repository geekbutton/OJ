// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
80. ɾ�����������е��ظ��� II
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/description/

����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ�
�����Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
*/

/*����˼·�� :	����26�⣬˼·������������ָ�룬һ��ָ��ǰ������λ�ã�һ��ָ��ǰ
������Ԫ�ء�Ψһ�Ĳ�ͬ���ڸ���ÿ��Ԫ�������Գ������Σ������Ҫ����һ��������жϡ�
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int p1 = 0, p2 = 0;
		int num = nums.size();
		int count = 0;
		//�����ҵ���һ���ɲ����λ�ã�����һ�γ�����Ԫ����ͬʱ������Ԫ�ص�λ��
		for (int i = 0; i < num - 2; ++i) {
			if (nums[i] != nums[i + 1] || nums[i + 1] != nums[i + 2]) {
				++count;
				continue;
			}
			p1 = i + 2;
			count += 2;
			break;
		}
		if (!p1)					//p1Ϊ0��˵�������ڳ����������ظ�Ԫ�أ�ֱ�ӷ���
			return num;
		//���򣬴�p1��λ�ÿ�ʼ�������ҵ���һ��������nums[p1]��Ԫ�أ��Ӹ�Ԫ�ؿ�ʼ����p2
		for (int i = p1; i < num; ++i) {
			if (nums[i] == nums[p1])
				continue;
			p2 = i;
			break;
		}
		//p2��Ϊ0�����������������ֱ�ӷ���
		if (p2) {
			for (p2; p2 < num - 2; ++p2) {
				//ע��Ԫ�صĲ���ʱ��
				//��ʾ��Ԫ��������ʱ(Ҳ�����ǵ���Ԫ�صĵ�һ�γ���)������һ��
				if (nums[p2] != nums[p2 + 1]) {
					nums[p1++] = nums[p2];
					++count;
					continue;
				}
				//��ʾ��Ԫ��ֻʣ������ʱ������һ��
				else if (nums[p2 + 1] != nums[p2 + 2]) {
					nums[p1++] = nums[p2 + 1];
					++count;
					continue;
				}
			}
			//����p2���յ������Ԫ�أ����Բ���ʹ��ǰ���Ԫ�س�������
			for (--p2; p2 < num; ++p2) {
				nums[p1++] = nums[p2];
				++count;
			}
			return count;
		}
		return count;
	}
};