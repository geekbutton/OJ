// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
66. ��һ
https://leetcode-cn.com/problems/plus-one/description/

����һ���Ǹ�������ɵķǿ����飬�ڸ����Ļ����ϼ�һ������һ���µ����顣
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��
*/

/*����˼·�� :	���ʾ���һ��ʮ���Ƽӷ���ע���λ�Ĵ����ر������λ�Ľ�λ��
�����λ���ڽ�λʱ����Ҫ��������һ��Ԫ������������λ�á�
*/
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int flag = 1;			//ע�⣬flag��ʾ��λ����ʼֵΪ1����Ϊ���λ��Ҫ��1
		for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
			int value = (*iter + flag) % 10;
			flag = (*iter + flag) / 10;
			*iter = value;
			if (!flag)
				break;
		}

		if (flag) {
			digits.insert(digits.begin(), flag);
		}
		return digits;
	}
};
