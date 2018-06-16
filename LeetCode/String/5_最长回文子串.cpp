// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
5. ������Ӵ�
https://leetcode-cn.com/problems/longest-palindromic-substring/description/

����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ1000��
*/

/*����˼·�� :	��һ�ַ�������������п�ʼ������������ص�һ�����Ĵ���Ϊ�����Ĵ������÷���
ʱ�临�ӶȽϸߡ��ڶ��ַ�����MMNACHER�㷨(https://www.cnblogs.com/TenosDoIt/p/3675788.html)
*/
class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.size();
		if (!length)
			return string();
		while (length) {
			for (int i = 0; i < s.size() - length + 1; ++i) {
				int r = i + length - 1;
				int j = i;
				for (; j < i + length / 2; ++j) {
					if (s[j] != s[r])
						break;
					--r;
				}
				if (j == i + length / 2) {
					return s.substr(i, length);
				}
			}
			--length;
		}
	}
};

string preprocess(string&);
class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.size();
		int mx = 0, id = 0;
		string res = preprocess(s);
		vector<int> p(res.size(), 0);
		for (int i = 1; i < res.size(); ++i) {
			//�ؼ������
			p[i] = mx > i ? (min(p[2 * id - i], mx - i)) : 1;
			//�������ܷ������iΪ����ƥ��
			while ((i - p[i] >= 0) && res[i + p[i]] == res[i - p[i]])
				++p[i];
			//���ƥ�䵽������ֵ������֮ǰ������ֵ�����������ֵ�Ͷ�Ӧ����
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		//�����Ӵ��������飬�ҵ���Ӵ�p[i]-1
		int max_length = 0, index = 0;
		for (int i = 1; i < res.size(); ++i) {
			if (p[i] > max_length) {
				max_length = p[i];
				index = i;
			}
		}
		return s.substr((index - max_length + 1) / 2, max_length - 1);
	}
};
//��ԭʼ�ַ������'#'
string preprocess(string& s) {
	string res;
	for (int i = 0; i < s.size(); ++i) {
		res.push_back('#');
		res.push_back(s[i]);
	}
	res.push_back('#');
	return res;
}