// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
10. ������ʽƥ��
https://leetcode-cn.com/problems/regular-expression-matching/description/

����һ���ַ��� (s) ��һ���ַ�ģʽ (p)��ʵ��֧�� '.' �� '*' ��������ʽƥ�䡣
����һ���ַ��� (s) ��һ���ַ�ģʽ (p)��ʵ��֧�� '.' �� '*' ��������ʽƥ�䡣
*/

/*����˼·�� :	���ö�̬�滮��⣬����iv[i][j]��ʾ�ַ���s[0..i)�Ƿ�ƥ����ʽp[0...j),
״̬ת�Ʒ���Ϊ��
	1.	iv[i][j] = iv[i-1][j-1], ���p[j-1]!='*'��(s[i-1]==p[i-1] || p[i-1]=='.')������
	��ǰƥ���ַ���Ϊ*ͨ���ʱ�������ǰƥ���ַ����ڵ�ǰ�ַ������ܷ�ɹ�ƥ��ȡ����ǰһ״̬��
	2.	iv[i][j] = iv[i][j-2], ���p[j-1]=='*'����ǰһ�ַ���δ���֣����ܷ�ɹ�ƥ��ȡ����
	��*��֮ǰ��֮ǰ��Ԫ���ܷ�ɹ�ƥ�䡣
	3.	iv[i][j] = iv[i-1][j] && (s[i-1]==p[j-2] || p[j-2] == '.'), ���p[j-1]=='*'
	����ͨ���ַ����ֹ�����һ�Ρ���ʱ�ܷ�ɹ�ƥ��ȡ����p[j-2]��ӦԪ���ܷ�ɹ�ƥ��s[i-1]
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool> > iv(m + 1, vector<bool>(n + 1, false));
		iv[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] == '*')
					iv[i][j] = iv[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && iv[i - 1][j]);
				else iv[i][j] = i > 0 && iv[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				return iv[m][n];
	}
};