// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
84. ��״ͼ�����ľ���
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/

���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*/

/*����˼·�� :	����ջ��������ʵ��O(n)���ӶȵĽⷨ������һ������ջ����Ԫ�ش��ڵ���ջ��Ԫ��
ʱֱ������ջ�У���С��ʱ�����ջ�е���Ԫ�ؼ����Ӧ�����֪��ջ��Ԫ��С�ڵ�ǰԪ��
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int num = heights.size();
		int result = heights[0], index_0 = 0;
		stack<int> is;
		is.push(0);
		for (int i = 1; i < num; ++i) {
			if (is.empty() || heights[i] >= heights[is.top()]) {
				is.push(i);
				continue;
			}
			while (!is.empty() && heights[is.top()] > heights[i]) {
				int index = is.top();
				int value = heights[index];
				is.pop();
				//�ؼ��������������Ĺ�ʽ������ջ�е����һ��Ԫ�غͷ����һ��Ԫ��
				result = max(result, value*(is.empty() ? i : (i - 1 - is.top())));
			}
			is.push(i);
		}
		heights.pop_back();
		return result;
	}
};