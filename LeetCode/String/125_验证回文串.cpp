// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
125. ��֤���Ĵ�
https://leetcode-cn.com/problems/valid-palindrome/description/

����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
*/

/*����˼·�� :	�ж����Ĵ��Ķ��������档���ȱ����ַ���ȥ�����в����ǵ��ַ���ͬʱ�����д�д�ַ�
ת����Сд�ַ�(���෴����Ϊ�����в����ִ�Сд)����ʱ���ɰ��մ�����ͨ���Ĵ��ķ������д�������
��ͷβָ��ͬʱ���м��ƶ����ж�����ָ��������Ƿ���ȣ�����ȿ�����ǰ�˳���
*/
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)
			return true;
		string value;
		for (int i = 0; i < s.size(); ++i) {
			if ((s[i] >= '0' && s[i] <= '9'))
				value.push_back(s[i]);
			else if (s[i] >= 'A' && s[i] <= 'Z')
				value.push_back(s[i] + 32);
			else if (s[i] >= 'a' && s[i] <= 'z')
				value.push_back(s[i]);
		}
		for (int i = 0, j = value.size() - 1; i <= j; ++i, --j) {
			if (value[i] != value[j])
				return false;
		}
		return true;
	}
};