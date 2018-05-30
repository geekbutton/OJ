// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
179. �����
https://leetcode-cn.com/problems/largest-number/description/


����һ��Ǹ������������������ǵ�˳��ʹ֮���һ������������
*/

/*����˼·�� :	����һ��compare������ָ��һ�������ж������ַ���������˳���µĴ�С������
���򣬴�����������ɺ�Ӻ���ǰ���ַ����ۼӼ��ɵ����ս����
ע�����������С����˼��������(�������޸�comp�ж���������)��
*/
bool comp(string s1, string s2);
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> sv;
		string result;
		for (auto x : nums) {
			sv.push_back(to_string(x));
		}
		sort(sv.begin(), sv.end(),comp);
		for (auto iter = sv.rbegin(); iter != sv.rend(); ++iter) {
			result += *iter;
		}
		int i = 0;
		//����ȫ0��״����
		while (result[i] == '0' && i < result.size() - 1) {
			++i;
		}
		result = result.substr(i);
		return result;
		
	}
};
//�Զ���ȽϺ�����������С��������Ҳ���Է���
bool comp(string s1, string s2) {
	return s1 + s2 < s2 + s1;
}