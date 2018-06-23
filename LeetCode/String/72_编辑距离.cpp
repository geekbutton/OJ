// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
72. �༭����
https://leetcode-cn.com/problems/edit-distance/description/

������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ����� ��
����Զ�һ�����ʽ����������ֲ�����
	����һ���ַ�
	ɾ��һ���ַ�
	�滻һ���ַ�
*/

/*����˼·�� :	��Ȼ�����ö�̬�滮���뷨������⡣���ڵ�0�к͵�0�У���Ӧ�༭���뼴Ϊ
��ʱ��Word1���Ȼ�word2���ȡ�����word1[i-1]==word2[j-1]�������dp[i][j]=dp[i-1][j-1]��
��༭����ȡ������ǰ���ַ���ת�����е����ٲ�����(��Ϊ��ȣ������ڸ��ַ��ϲ���Ҫ�κβ���)��
���ڲ��ȵ��������Ϊ�������ȡ��Сֵ��
	1.	�滻һ���ַ�����dp[i][j] = dp[i-1][j-1]+1����ǰһ�ַ�ת���ɹ��Ļ����Ͻ���һ���滻����
	2.	ɾ��һ���ַ�����dp[i][j] = dp[i - 1][j] + 1������ǰһ�ַ�ת���ɹ��Ļ�����ɾ�����ַ�
		word1[i-1]
	3.	����һ���ַ�����dp[i][j] = dp[i][j - 1] + 1�����ɹ�ת����ǰһ�ַ���������������һ��
		�ַ�ת��=�����ӵ�word2[j-1]
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int i = 0, j = 0;
		int count = 0;
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word2.size(); ++i) {
			dp[0][i] = i;
		}
		for (int i = 0; i <= word1.size(); ++i) {
			dp[i][0] = i;
		}
		for (int i = 1; i <= word1.size(); ++i) {
			for (int j = 1; j <= word2.size(); ++j) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {	//ת�������ֲ���
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}
};