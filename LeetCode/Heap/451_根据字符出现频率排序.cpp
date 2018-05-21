// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
451. �����ַ�����Ƶ������

https://leetcode-cn.com/problems/sort-characters-by-frequency/description/

����һ���ַ������뽫�ַ�������ַ����ճ��ֵ�Ƶ�ʽ������С�
*/

/*ע��ʱ�临�Ӷȴ��������⣬Ӧ��ʹ�ù�ϣ��Ӷѵ���ϣ���Ӧ���ǲ��ù�ϣ��Ϊ�ײ�ʵ�ֵ�
unordered_map
*/
class Solution {
public:
	string frequencySort(string s) {
		if (s.size() == 0)
			return s;
		unordered_map<char, int> ism;
		priority_queue<pair<int, char>> iq;
		for (auto ch : s)
			++(ism[ch]);
		for (auto iter : ism)
			iq.push({ iter.second,iter.first });		//ע��������е�map����ֵ������˳��
		for (int i = 0; i < s.size(); i) {
			int frequency = iq.top().first;
			char value = iq.top().second;
			while (frequency--)
				s[i++] = value;
			iq.pop();
		}
		return s;
	}
};
