// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
28. ʵ��strStr()
https://leetcode-cn.com/problems/implement-strstr/description/

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)��
��������ڣ��򷵻�  -1���� needle �ǿ��ַ���ʱ����Ӧ������ 0 ��
*/

/*����˼·�� :	����KMP�㷨�����Ӵ����ؼ����������칹�첿��ƥ����ύ���ֲ���ƥ����
��������Ӱ���㷨������ʱ�临�Ӷȡ�
*/
vector<int> Partial_matching(string);
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		vector<int> iv(needle.size(), 0);
		iv = Partial_matching(needle);

		int match_index = 0;
		int i = 0;
		for (i = 0; i < haystack.size() && match_index < needle.size();) {
			if (match_index == 0 && haystack[i] != needle[0]) {
				++i;
				continue;
			}
			else if (match_index == 0 && haystack[i] == needle[0]) {
				match_index = 1;
				++i;
				continue;
			}
			else if (haystack[i] == needle[match_index]) {
				++i; ++match_index;
				continue;
			}
			else {
				match_index = iv[match_index - 1];
				continue;
			}
		}
		if (match_index == needle.size())
			return i - needle.size();
		return -1;
	}
};
//ע��������ⲿ��ƥ���ķ�����һ�μ����������ֵ
vector<int> Partial_matching(string s) {
	vector<int> iv(s.size(), 0);
	if (s.size() == 0)
		return iv;
	int max_length = 0;
	//��Ӧ���������i��Ӧ�ַ���ƥ��ͷ��j��Ӧ��ǰƥ��λ��
	for (int i = 0, j = 1; j < s.size();) {
		if (s[i] == s[j])		//�����ͬʱ�ƶ�i��j
			iv[j++] = ++i;
		else if (i)				//�������i�����ַ���ͷ����������ָ��i��λ�á�������������һ������ϲ���ƥ����������
			i = iv[i-1];
		else ++j;				//�������i��Ȼ���ַ���ͷ���򱣳�i�������ƶ�j
	}
	return iv;
}