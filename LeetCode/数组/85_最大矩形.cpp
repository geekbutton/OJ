// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
85. ������
https://leetcode-cn.com/problems/maximal-rectangle/description/

����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������
*/

/*����˼·�� :	���ø�84��һ���Ľ���˼·����������ȴ����һ��������������ٽ��ڶ���
ƴ������һ���ϣ�ע�⵱�µ�һ�ж�Ӧλ��Ϊ0ʱ����ϲ�ʱ��ȻΪ0������++��
*/
void max_rectangle(vector<int>&, int&);
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<int> iv(matrix[0].size(), 0);
		int result = matrix[0][0] - '0';
		//�ӵ�һ�п�ʼ���а���84��ⷨ���һά����������
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				//�����Ԫ��Ϊ0����������0������++
				iv[j] = (matrix[i][j] - '0') ? (iv[j] + 1) : 0;
			}
			max_rectangle(iv, result);
		}
		return result;
	}
};
//ͬ84��������
void max_rectangle(vector<int>& matrix, int& result) {
	matrix.push_back(0);		//ĩβ��0��ȷ������Ԫ�ض����ջ
	stack<int> is;
	is.push(0);
	for (int i = 1; i < matrix.size(); ++i) {
		//ע���ж�������ͬʱע��ջ�д洢��Ϊ���������Ƕ�Ӧֵ
		if (is.empty() || matrix[i] >= matrix[is.top()]) {
			is.push(i);
			continue;
		}
		while (!is.empty() && matrix[i] < matrix[is.top()]) {
			int index = is.top();
			int value = matrix[index];
			is.pop();
			result = max(result, value*(is.empty() ? (i) : (i - 1 - is.top())));
		}
		is.push(i);
	}
	matrix.pop_back();
	return;
}