// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
58. ���һ�����ʵĳ���
https://leetcode-cn.com/problems/length-of-last-word/description/

����һ����������Сд��ĸ�Ϳո� ' ' ���ַ��������������һ�����ʵĳ��ȡ�
������������һ�����ʣ��뷵�� 0 ��
˵����һ��������ָ����ĸ��ɣ����������κοո���ַ�����
*/

/*����˼·�� :	ûʲô��˵�ģ�������Ҽ��ɱ�֤������ʱ�临�Ӷ���ɡ�
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int num = s.size(), result = 0;
		int i = num - 1;
		//��������ĩβ�Ŀո�
		for (i; i >= 0; --i) {
			if (s[i] == ' ')
				continue;
			break;
		}
		//��ĩβ��һ���ǿ��ַ���ʼ�������ֱ�����ֿո�򵽴��ַ���ͷ��ע�⣬ֻ��һ������
		//ʱ����ǵ�һ������Ҳ�����һ������
		for (; i >= 0; --i) {
			if (s[i] == ' ')
				break;
			++result;
		}
		return result;
	}
};