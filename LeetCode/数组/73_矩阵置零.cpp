// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
73. ��������
https://leetcode-cn.com/problems/set-matrix-zeroes/description/

����һ�� m x n �ľ������һ��Ԫ��Ϊ 0�����������к��е�����Ԫ�ض���Ϊ 0��
��ʹ��ԭ���㷨��
*/

/*����˼·�� :	����Ԫ�أ���Ԫ��Ϊ0ʱ�����������к��е���Ԫ��Ϊ0��
ע���matrix[0][0]Ԫ�صĴ�����Ϊ��ȴ�������Ԫ��Ҳ��������Ԫ�أ�����Ϊ������
������������ı�־��flag_c��flag_r��ʾ��һ�У���һ���Ƿ���Ҫ��0��
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int flag_r = 0, flag_c = 0;			//�����һ�к͵�һ�еı�־
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if ((i && j) && matrix[i][0] == 0 && matrix[0][j] == 0)
					continue;
				//Ԫ��Ϊ0�����Ӧ������Ԫ����0����flag_c��flag_r��0
				if (matrix[i][j] == 0) {
					if (i && j) {
						matrix[i][0] = 0;
						matrix[0][j] = 0;
						continue;
					}
				    if (!i && !flag_r) {
						flag_r = 1;
					}
				    if (!j && !flag_c)
						flag_c = 1;
				}
			}
		}
		//���ݸ��и�����Ԫ���Ƿ�Ϊ0�жϸ������Ƿ���Ҫȫ����0
		for (int i = 1; i < rows; ++i) {
			if (!matrix[i][0]) {
				for (int j = 1; j < cols; ++j)
					matrix[i][j] = 0;
			}
		}
		for (int i = 1; i < cols; ++i) {
			if (!matrix[0][i]) {
				for (int j = 1; j < rows; ++j)
					matrix[j][i] = 0;
			}
		}
		if (flag_r) {
			for (int i = 0; i < cols; ++i)
				matrix[0][i] = 0;
		}
		if (flag_c) {
			for (int i = 0; i < rows; ++i)
				matrix[i][0] = 0;
		}
	}
};
