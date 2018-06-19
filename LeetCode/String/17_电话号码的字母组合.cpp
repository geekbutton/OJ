// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
17. �绰�������ĸ���
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/

����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
*/

/*����˼·�� :	������ȱ������������е�������������
*/
void Combination(string&, int, vector<vector<string>>&, string&, vector<string>&);
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (!digits.size())
			return vector<string>();
		unordered_set<string> ss;
		vector<string> result;
		string temp_result;
		vector<vector<string>> lib{ {"a","b","c"},{"d","e","f"},{ "g","h","i" },
							{ "j","k","l" },{ "m","n","o" },{ "p","q","r","s" },
							{ "t","u","v" },{ "w","x","y","z" } };
		Combination(digits, 0, lib, temp_result, result);
		return result;
	}
};

//ʵ��������ȱ���
void Combination(string& digits, int index, vector<vector<string>>& lib, string& temp_result, vector<string>& result) {
	int map_index = digits[index] - '0';
	vector<string> temp_lib = lib[map_index - 2];
	// ����������Ԫ��Ϊ���һ��Ԫ���򽫵�ǰ��Ͻ����������ս����
	if (index == digits.size() - 1) {
		for (int i = 0; i < temp_lib.size(); ++i) {
			temp_result += (temp_lib[i]);
			result.push_back(temp_result);
			temp_result.pop_back();			//ע��ÿ���˳�ʱɾ�����һ��Ԫ��
		}
	}
	else {
		for (int i = 0; i < temp_lib.size(); ++i) {
			temp_result += (temp_lib[i]);	//���ӵ�ǰԪ�أ���������һ��ֵ����
			Combination(digits, index + 1, lib, temp_result, result);
			temp_result.pop_back();			//ע��ÿ���˳�ʱɾ�����һ��Ԫ��
		}
	}
}