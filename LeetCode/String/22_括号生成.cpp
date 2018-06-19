// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
22. ��������
https://leetcode-cn.com/problems/generate-parentheses/description/

���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�
���磬���� n = 3�����ɽ��Ϊ��
*/

/*����˼·�� :	����17��Ľⷨ�����20���ж����ŵĺϷ��ԣ������㷨�ĵ������⡣
*/
void Combination(int, string, vector<string>&, stack<char>);
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (!n)
			return vector<string>();
		stack<char> cs;
		vector<string> result;
		string temp_str;
		int count = 0;
		Combination(n, temp_str, result, cs);
		return result;
	}
};
//ע��temp_str��cs������д���в����Ǵ�����
void Combination(int n, string temp_str, vector<string>& result, stack<char> cs) {
	if (!n) {			//���n����0����˵�������������Ѿ������ϣ���ʱֻ����������ţ����ؽ��
		for (int i = 0; i < cs.size(); ++i)
			temp_str += ')';		//����ջ�������ŵ���Ŀ��������ţ������Ӧ���ս��
		result.push_back(temp_str);
		return;
	}
	if (cs.size() == 0) {		//���ջΪ�գ����ʱֻ�����������
		cs.push('(');
		temp_str += '(';
		Combination(n - 1, temp_str, result, cs);
	}	
	else {			//���ջ��Ϊ�գ��������������Ż����������
		cs.push('(');
		temp_str += '(';
		Combination(n - 1, temp_str, result, cs);	//��������ţ�n��1
		cs.pop();			//��������ţ�ɾ���ղ���ӵ������ż������������ƥ���������
		cs.pop();			//����ɾ������
		temp_str.pop_back();	//ɾ���ղ���ӵ�������
		temp_str += ')';		//���ƥ���������
		Combination(n, temp_str, result, cs);	//������������ʱ��Ϊû����������ţ����n���ֲ���
	}
}