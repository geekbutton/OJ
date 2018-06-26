// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
97. �����ַ���
https://leetcode-cn.com/problems/interleaving-string/description/

���������ַ��� s1, s2, s3, ��֤ s3 �Ƿ����� s1 �� s2 ������ɵġ�
*/

/*����˼·�� :	���ö�̬�滮������⡣
*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int num1 = s1.size(), num2 = s2.size();
		if (num1 + num2 != s3.size())
			return false;
		vector<vector<int>> iv(num1 + 1, vector<int>(num2 + 1, 0));
		iv[0][0] = 1;			//����iv[0][0]Ϊ1
		for (int i = 0; i <= num1; ++i) {
			for (int j = 0; j <= num2; ++j) {
				if (i + j == 0)
					continue;
				int index = i + j;		//��ʾ��ǰ��s3�е�ƥ��λ��
				if (i > 0)
					iv[i][j] = (iv[i - 1][j] && (s3[index - 1] == s1[i - 1]));
				if (j > 0)
					iv[i][j] = iv[i][j] || iv[i][j - 1] && (s3[index - 1] == s2[j - 1]);
			}
		}
		return iv[num1][num2];
	}
};
