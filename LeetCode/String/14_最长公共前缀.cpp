// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
14. �����ǰ׺
https://leetcode-cn.com/problems/longest-common-prefix/description/

��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��
*/

/*����˼·�� :	���ƥ��ǰ׺��ÿ�δ�ͷƥ�䵽ǰ׺����󳤶��Խ�ʡʱ�䡣
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int num = strs.size();
		if (num == 0)
			return "";
		if (num == 1)
			return strs[0];
		string result;
		int temp = min(strs[0].size(), strs[1].size());
		for (int i = 0; i < temp; ++i) {
			if (strs[0][i] != strs[1][i])
				break;
			result += strs[0][i];
		}
		// ��������Ԫ�ز��ң������ҳ���Ϊ��ǰǰ׺�ĳ��ȡ��ҵ�ǰ׺Ϊ��ʱ��ǰ�˳�
		for (int i = 2; i < num && result.size(); ++i) {
			for (int j = 0; j < result.size(); ++j) {
				if (strs[i][j] == result[j])
					continue;
				result.resize(j);
				break;
			}
		}
		return result;
	}
};