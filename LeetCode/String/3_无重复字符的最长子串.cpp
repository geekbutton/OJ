// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
3. ���ظ��ַ�����Ӵ�
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/

����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�(ָ���������ַ���)
*/

/*����˼·�� :	��ͷ��ʼ����������һ������set��ÿ�β���Ԫ��ǰ�жϸ�Ԫ���Ƿ���ڣ� ��������ֱ��
���룬�����ָ��ͷλ�ÿ�ʼ����ɾ��ֱ��ɾ�����ظ�Ԫ�ص�һ�γ��ֵ�λ�á�
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0, temp_result = 0;
		int l = 0, r = 0;				//λ��������������ǰ�Ӵ�������λ�ã����ڸ����Ӵ�
		unordered_set<int> is;			//����һ������set���������Ƿ�����ظ�Ԫ��
		for (int i = 0; i < s.size(); ++i) {
			if (is.empty()) {
				is.insert(s[i]);
				temp_result = 1;
				continue;
			}//�������ظ�Ԫ����ֱ�Ӳ���
			if (is.find(s[i]) == is.end()) {
				is.insert(s[i]);
				++temp_result;
				continue;
			}
			//�����ظ�Ԫ���������ǰ�Ӵ������ظ�Ԫ�أ�����·���ϵ�����Ԫ��ɾ��
			r = i;
			result = max(result, temp_result);			//�����ظ�Ԫ�������result
			for (l; l < r; ++l) {
				if (s[l] != s[i]) {
					is.erase(s[l]);
					continue;
				}
				temp_result = r - l;
				++l;
				++r;
				break;
			}
		}
		return max(result, temp_result);			//ע�⣬�˳�ѭ�������Ҫ����һ��result
	}
};