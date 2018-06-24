// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
67. ���������
https://leetcode-cn.com/problems/add-binary/description/

���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
*/

/*����˼·�� :	�����Ϻ�ʮ���Ƽӷ�û��ʲô���𣬲�֮ͬ������ʮ���Ƽӷ��Ƕ�10����
�����࣬���������Ƕ�2���̺�����
*/
class Solution {
public:
	string addBinary(string a, string b) {
		int num1 = a.size(), num2 = b.size();
		int flag = 0, i = num1 - 1, j = num2 - 1;
		string result;
		for (; i >= 0 && j >= 0; --i, --j) {
			int value = (a[i] - '0' + b[j] - '0' + flag) % 2;
			flag = (a[i] - '0' + b[j] - '0' + flag) / 2;
			result.insert(0, to_string(value));
		}
		while (i >= 0) {
			int value = (a[i] - '0' + flag) % 2;
			flag = (a[i] - '0' + flag) / 2;
			result.insert(0, to_string(value));
			--i;
		}
		while (j >= 0) {
			int value = (b[j] - '0' + flag) % 2;
			flag = (b[j] - '0' + flag) / 2;
			result.insert(0, to_string(value));
			--j;
		}
		while (flag) {
			int value = flag % 2;
			flag = flag / 2;
			result.insert(0, to_string(value));
		}
		return result;
	}
};