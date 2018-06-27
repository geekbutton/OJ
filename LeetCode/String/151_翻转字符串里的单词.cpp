// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
151. ��ת�ַ�����ĵ���
https://leetcode-cn.com/problems/reverse-words-in-a-string/description/

����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
ʾ��:
	����: "the sky is blue",
	���: "blue is sky the".

˵��:
	�޿ո��ַ�����һ�����ʡ�
	�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
	����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
����: ��ѡ��C���Ե��û�����ʹ�� O(1) ʱ�临�Ӷȵ�ԭ�ؽⷨ��
*/

/*����˼·�� :	��˳������ַ��������𵥴ʷ�ת����������ַ�����ת���ɵõ���ת����ַ�����
Ҫע������ַ����ж���ո�Ĵ����������Ҳ��õ���˫ָ����λ��λ�ķ�ʽ����������ͷβ��
���ַ�ֱ���ڿ�ʼʱ�������ӵ�һ���ǿ��ַ��������һ���ǿ��ַ���
*/
class Solution {
public:
	void reverseWords(string &s) {
		int l = 0, r = 0;
		//������ͷ�Ŀ��ַ�
		while (r < s.size()) {
			if (s[r] == ' ') {
				++r; continue;
			}
			break;
		}
		int l_index = r, r_index = s.size() - 1;		//��β�ǿ�Ԫ������
		l = r;
		//������β�Ŀ��ַ�
		while (r_index >= l_index) {
			if (s[r_index] == ' ') {
				--r_index;
				continue;
			}
			break;
		}
		//�����ַ������𵥴ʷ�ת
		for (r; r < r_index; ++r) {
			if (s[r] == ' ') {
				if (l == r) {
					l = r + 1;
					continue;
				}
				reverse(s.begin() + l, s.begin() + r);
				l = r + 1;
			}
		}
		if (l < r)		//ע�⴦�����һ�����ʷ�ת
			reverse(s.begin() + l, s.begin() + r + 1);
		s = s.substr(l_index, r_index - l_index + 1);
		reverse(s.begin(), s.end());

		//ͨ������ָ�����in-place�ķ�ʽ�������Ŀհ��ַ�
		l = 1, r = 1;
		for (; r < s.size(); ++r) {
			if (s[r] == ' ' && s[r - 1] == ' ')
				continue;
			s[l] = s[r];
			++l;
		}
		if (s.size() > l)
			s.resize(l);
	}
};