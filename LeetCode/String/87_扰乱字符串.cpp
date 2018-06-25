// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
87. �����ַ���
https://leetcode-cn.com/problems/scramble-string/description/

���������������Ŀҳ��
*/

/*����˼·�� :	˼·�����õݹ��㷨��ʵ�֣���˼·�����s1��s2�������ַ�������ض�����һ���з�
λ�ý�s1��Ϊs1_1��s1_2����s2��Ϊs2_1��s2_2����ʱs1_1��s2_1ӦΪ�����ַ�������s1_2��s2_2ӦΪ����
�ַ���������s1_1��s2_2ӦΪ�����ַ�������s1_2��s2_1ӦΪ�����ַ�����
*/
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)				//�������򷵻�true
			return true;
		if (s1.size() != s2.size())	//���s1��s2��С�����ȣ����Ȼ���������ַ���
			return false;
		//ע�����֮���Խ������ַ��������Ƚ���Ϊ�˸����ٵ��жϳ����߲��������ַ���
		//�����Σ�����������������������ַ������ַ������в���жϣ���ʵ֤�����û������
		//�������ջᳬʱ��
		string temp_1 = s1, temp_2 = s2;
		sort(temp_1.begin(), temp_1.end());
		sort(temp_2.begin(), temp_2.end());
		if (temp_1 != temp_2)
			return false;
		for (int i = 1; i < s1.size(); ++i) {
			string s1_1 = s1.substr(0, i);
			string s1_2 = s1.substr(i);
			string s2_1 = s2.substr(0, i);
			string s2_2 = s2.substr(i);
			//�ȴ���ͷ��ͷ��β��β�����
			if (isScramble(s1_1, s2_1) && isScramble(s1_2,s2_2))	//ע�����Ҫ�����ָ�����Ӵ����������
				return true;
			s2_1 = s2.substr(0, s1.size() - i);
			s2_2 = s2.substr(s1.size() - i);
			//������ʱ����ͷ��β��β��ͷ�����
			if (isScramble(s1_1, s2_2) && isScramble(s1_2, s2_1))
				return true;
		}
		return false;
	}
};