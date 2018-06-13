// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
119. ������� II
https://leetcode-cn.com/problems/pascals-triangle-ii/description/

����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
*/

/*����˼·�� :	�����ϸ�118����һ���ģ��������ڿռ临�Ӷ���Ҫ����ʵ�������������εĵ�k
�б�����ֻ��Ҫ��ǰһ�еĽ�����ɣ�����������鼴��ѭ����⡣
*/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		++rowIndex;				//ע��rowIndex��ʾ����ڼ��У�������0��ʼ
		vector<int> result = { 1 };
		for (int i = 1; i < rowIndex; ++i) {
			vector<int> iv{ 1 };
			for (int j = 1; j < i + 1; ++j) {
				if (j == i) {
					iv.push_back(1);
					result = iv;		//result��Ϊÿһ�������ɺ�Ľ����ͬʱ���������һ��
					break;
				}
				else {		//result��Ϊÿһ�������ɺ�Ľ����ͬʱ���������һ��
					iv.push_back(result[j - 1] + result[j]);
					continue;
				}
			}
		}
		return result;
	}
};