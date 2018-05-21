// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
378. ��������е�KС��Ԫ��

https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

����һ�� n x n ��������ÿ�к�ÿ��Ԫ�ؾ������������ҵ������е�kС��Ԫ�ء�
��ע�⣬���������ĵ�kСԪ�أ������ǵ�k��Ԫ�ء�
*/
/*���ö���⣬ע��C++��ֻ�����ȶ��м���˶ѣ�����Ҫ�������KСԪ�أ����ע��������ת��
ʱ�临�Ӷ�
*/
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> iq;
		int num = matrix.size();
		int n = 1;
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				iq.push(matrix[i][j]);					//����(��˶�)
			}
		}
		while (n != num*num - k + 1) {					//һ���Ƴ�ǰ��Ĵ���
			iq.pop();
			++n;
		}
		return iq.top();
	}
};
