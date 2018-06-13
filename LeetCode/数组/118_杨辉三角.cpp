// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
118. �������
https://leetcode-cn.com/problems/pascals-triangle/description/

����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
*/

/*����˼·�� :	ûʲô��˵�ģ������������������
*/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0) {
			return vector<vector<int>>();
		}
		vector<vector<int>> result{ vector<int>{1} };
		for (int i = 1; i < numRows; ++i) {
			vector<int> iv{ 1 };
			int num = i + 1;
			for (int j = 1; j < num; ++j) {
				if (j == i) {
					iv.push_back(1);
					result.push_back(iv);
					break;
				}
				else {
					iv.push_back((result[i - 1][j - 1] + result[i - 1][j]));
					continue;
				}
			}
		}
		return result;
	}
};