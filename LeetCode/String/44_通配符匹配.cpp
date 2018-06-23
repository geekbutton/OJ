// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
44. ͨ���ƥ��
https://leetcode-cn.com/problems/wildcard-matching/description/

����һ���ַ��� (s) ��һ���ַ�ģʽ (p) ��ʵ��һ��֧�� '?' �� '*' ��ͨ���ƥ�䡣
	'?' ����ƥ���κε����ַ���
	'*' ����ƥ�������ַ������������ַ�������
�����ַ�����ȫƥ�����ƥ��ɹ���
*/

/*����˼·�� :	����ϰ��10��������ʽ������˼·�������ö�̬�滮������⡣������ֳ���
����������д���ͬʱ�Ե�һ���ַ����ж����ж���
	1.	ͨ�����Ϊ*�򣿣���iv[i][i] = iv[i - 1][j - 1] && (p[j - 1] == s[i - 1])����
		ȡ����ǰһ��λ���Ƿ�ɹ�ƥ��͵�ǰ�ַ��ܷ�ɹ�ƥ�䡣
	2.	ͨ���Ϊ����iv[i][j] = iv[i - 1][j - 1]����ȡ����ǰһ��λ�����ܷ�ɹ�ƥ�䡣
	3.	ͨ���Ϊ*��ֻҪǰһͨ����ܳɹ�ƥ�����ⳤ�ȵĴ�ƥ���ַ�����1��������iv[k][j-1]Ϊ1
		��iv[i][j]Ϊ1(k = 0,...,i)��
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		int count1 = s.size(), count2 = p.size();
		vector<vector<int>> iv(count1 + 1, vector<int>(count2 + 1, 0));
		iv[0][0] = 1;
		int flag = 1;
		//�����ж���ƥ���ַ��ĵ�һ���ַ�
		for (int i = 0; i < count2; ++i) {
			if (p[i] == '*') {			//ͨ���Ϊ*���Ӧλ��1����ְ�ܳ�����ͨ�����ͷ������ڵ�һ��ƥ�������
				iv[0][i + 1] = 1;
				if (count1 > 0)
					iv[1][i + 1] = 1;
				continue;
			}
			if (flag && count1 > 0 && (p[i] == s[0] || p[i] == '?')) {	//�ҵ���һ����Ϊ*���ַ�����ƥ��
				iv[1][i + 1] = 1;
				flag = 0;
				continue;
			}
			break;
		}
		//���ֶ�̬�滮״̬ת�Ʒ���
		for (int i = 2; i <= count1; ++i) {
			for (int j = 1; j <= count2; ++j) {
				if (p[j - 1] != '*' && p[j - 1] != '?') {
					iv[i][j] = iv[i - 1][j - 1] && (p[j - 1] == s[i - 1]);
				}
				else if (p[j - 1] == '?')
					iv[i][j] = iv[i - 1][j - 1];
				else if (p[j - 1] == '*') {
					for (int k = 0; k <= i; ++k) {
						if (iv[k][j - 1]) {
							iv[i][j] = 1;
							break;
						}
					}
				}
			}
		}
		return iv[count1][count2];
	}
};