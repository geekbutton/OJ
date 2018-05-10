// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
59. �������� II

https://leetcode-cn.com/problems/spiral-matrix-ii/description/
����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n,vector<int>(n,0));
		int iterations = n / 2;
		int num = 1;
		for (int i = 0; i < iterations; ++i) {
			//�������������������ĸ���ÿ�������߳�Ϊn��
			//����n-1�����Ա����ظ����������ε��ĸ�����
			for (int j = i; j < n - i - 1; ++j)
				result[i][j] = num++;
			for (int j = i; j < n - i - 1; ++j)
				result[j][n - i - 1] = num++;
			for (int j = n - i - 1; j > i; --j)
				result[n - 1 - i][j] = num++;
			for (int j = n - 1 - i; j > i; --j)
				result[j][i] = num++;
		}
		if (n % 2 == 1)						//����nΪ����ʱ�������ĵ��Ǹ�ֵ
			result[iterations][iterations] = num;
		return result;
	}
};

