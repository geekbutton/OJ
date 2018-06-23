// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
49. ��ĸ��λ�ʷ���
https://leetcode-cn.com/problems/group-anagrams/description/

����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
*/

/*����˼·�� :	���ù�ϣ����д������ȶ�ÿ��Ԫ�ؽ������򣬴Ӷ�ʹ����ĸ��λ�ʶ�Ӧ��ͬ�Ľ����
�������Ľ����Ϊkey������ǰ��Ԫ����Ϊvalue�����������ֵ��У��Ӷ����Եõ���ĸ��λ�ʵ���ϡ�
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> sm;
		int num = strs.size();
		for (int i = 0; i < num; ++i) {
			string value = strs[i];
			sort(value.begin(), value.end());
			sm[value].push_back(strs[i]);
		}
		//���map�е���������result�з���
		for (auto iter = sm.begin(); iter != sm.end(); ++iter) {
			result.push_back(iter->second);
		}
		return result;
	}
};