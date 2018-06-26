// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
115. ��ͬ��������
https://leetcode-cn.com/problems/distinct-subsequences/description/

����һ���ַ��� S ��һ���ַ��� T�������� S ���������� T ���ֵĸ�����
һ���ַ�����һ����������ָ��ͨ��ɾ��һЩ��Ҳ���Բ�ɾ�����ַ��Ҳ�����ʣ���ַ����λ������ɵ����ַ�����
�����磬"ACE" �� "ABCDE" ��һ�������У��� "AEC" ���ǣ�
*/

/*����˼·�� :	���ö�̬�滮������⡣���ַ���T���ַ���Ϊ�У�S���ַ���Ϊ�У�ͬʱ���һ������
���С����е�0��ȫΪ1����0�г���һ����ȫΪ0����̬�滮״̬ת�Ʒ�Ϊ���������
	1.	s[j-1]!=t[i-1]���������ַ�����ǰβ�ַ����ȣ����ʱiv[i][j]=iv[i][j-1]
	2.	s[j-1]==t[i-1]���������ַ�����ǰβ�ַ���ȣ���ʱiv[i][j]=iv[i-1][j-1]+iv[i][j-1],��
		��ǰT������S�еĴ�������ѡ����S��Tβ�ַ��������ַ��ĳ��ִ���+û��ѡ��S��β�ַ�ʱ����
		�ַ��ĳ��ִ�����
*/
class Solution {
public:
	int numDistinct(string s, string t) {
		int num1 = s.size(), num2 = t.size();
		vector<vector<int>> iv(num2 + 1, vector<int>(num1 + 1, 0));
		for (int i = 0; i <= num1; ++i)
			iv[0][i] = 1;
		for (int i = 1; i <= num2; ++i)
			iv[i][0] = 0;

		for (int i = 1; i <= num2; ++i) {
			for (int j = i; j <= num1; ++j) {
				if (s[j - 1] != t[i - 1]) {
					iv[i][j] = iv[i][j - 1];
					continue;
				}
				iv[i][j] = iv[i - 1][j - 1] + iv[i][j - 1];
			}
		}
		return iv[num2][num1];
	}
};
