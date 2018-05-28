// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
242. ��Ч����ĸ��λ��
https://leetcode-cn.com/problems/valid-anagram/description/

���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ��һ����ĸ��λ�ʡ�
*/

/*ûʲô��˵�ģ�ΨһҪע����Ǵ˴���Ϊ�����ַ�����ȫ��ͬҲ����ĸ��λ��
*/
class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> bucket(26, 0);
		for (auto x : s)
			++bucket[x - 'a'];
		for (auto x : t)
			--bucket[x - 'a'];
		for (auto x : bucket) {
			if (x != 0)
				return false;
		}
		return true;
	}
};