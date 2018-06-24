// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
76. ��С�����Ӵ�
https://leetcode-cn.com/problems/minimum-window-substring/description/

����һ���ַ��� S ��һ���ַ��� T������ S ���ҳ����� T ������ĸ����С�Ӵ���
*/

/*����˼·�� :	����һ����ϣ��map�洢t�е�ÿ��Ԫ�ؼ�����ִ���������һ����������ʾ������ƥ��
�ַ�����Ȼ�����s��ÿ�ε�s[i]������t��ʱ������map�ж��������1��ͬʱ����������ڵ���0ʱ����
count��1����count����t.size()���ʾ��ǰ�ַ�������ƥ��T��������С�Ӵ���Ȼ���ƶ��Ӵ���ָ�룬ֱ��
�Ӵ����ܰ���T������Ԫ�أ���ʱ������ָ�������ָ�롣�ظ�������̡�
*/
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> tm;
		//����map����T��Ԫ�ؼ���
		for (int i = 0; i < t.size(); ++i)
			++tm[t[i]];
		int count = 0;					//��ǰ����ƥ���ַ���
		int l = 0, r = 0, min_len = s.size() + 1;		//�������λ�ü���С�Ӵ�����
		string result;
		for (r; r < s.size(); ++r) {
			if (tm.find(s[r]) != tm.end()) {		//��s���ҵ�T�е�Ԫ�����Ӧ������1
				tm[s[r]]--;
				if (tm[s[r]] >= 0)			//ע�⣬ֻ�������ü������ڵ���0ʱ��count�ż�1��
					++count;				//��ʾ�������ַ�������
			}
			while (count == t.size()) {
				if (r - l + 1 < min_len) {		//������С�Ӵ�
					min_len = r - l + 1;
					result = s.substr(l, min_len);
				}
				if (tm.find(s[l]) != tm.end()) {	
					tm[s[l]]++;			//����Ӵ������Ԫ����T�У����Ӧ���ü�����1
					if (tm[s[l]] > 0)	//ע�⣬ֻ�е����ü�������0ʱ���Ÿı�count
						--count;		//��Ϊ����С��0����ǰ�Ӵ���Ȼ��������T��Ԫ�ص�Ԫ��
				}
				++l;					//������ָ��
			}

		}
		return result;
	}
};