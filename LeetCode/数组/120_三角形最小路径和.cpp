// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
120. ��������С·����
https://leetcode-cn.com/problems/triangle/description/

����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
��������ֻʹ�� O(n) �Ķ���ռ䣨n Ϊ�����ε��������������������⣬��ô����㷨��ܼӷ֡�
*/

/*����˼·�� :	�����Ͼ����������+��̬�滮��������ǵ�Ԫ�ز���������Ϊ�����е�����·����
�����㷨Ҫ��ʹ��O(n)�Ķ���ռ䣬���Զ��ڶ�̬�滮ֻ����ǰ�ν���͵��ν�����ǲ���һ��
n*n���������ڱ�������
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> result;
		int rows = triangle.size();
		if (!rows)
			return 0;
		result.push_back(triangle[0][0]);
		for (int i = 1; i < rows; ++i) {
			vector<int> temp = triangle[i];
			//ÿһ��ͷβԪ��ֻ������һ�е�ͷԪ��(βԪ��)����
			//�м�Ԫ�����ͨ��������ǵķ�ʽ�õ�������ͬ��·����ѡ��϶̵�·��
			vector<int> iv{ result[0] + temp[0] };
			for (int j = 1; j < i + 1; ++j) {
				if (j == i) {
					iv.push_back(result[result.size() - 1] + temp[j]);
					result = iv;
					break;
				}
				else {
					iv.push_back((result[j - 1] <= result[j] ? result[j - 1] : result[j]) + temp[j]);
					continue;
				}
			}
		}
		//���������һ�е����е�Ķ�Ӧ·�����ҵ����·��
		int minPath = result[0];
		for (auto x : result) {
			if (x < minPath)
				minPath = x;
		}
		return minPath;
	}
};