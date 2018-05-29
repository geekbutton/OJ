// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
524. ͨ��ɾ����ĸƥ�䵽�ֵ��������
https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/

����һ���ַ�����һ���ַ����ֵ䣬�ҵ��ֵ���������ַ��������ַ�������ͨ��ɾ�������ַ�����ĳЩ�ַ����õ�������𰸲�ֹһ����
���س�������ֵ�˳����С���ַ���������𰸲����ڣ��򷵻ؿ��ַ�����
*/

/*����˼·���Ƚ�ÿһ���ַ���������ַ����Ƚϣ��ҳ����������Ĵ������������������
����һ��set�������򣬵õ��ֵ����µ���ַ�����
*/
bool comp(const string&, const string&);
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		set<string> ss;
		vector<string> sv;
		int max_len = 0;
		for (int i = 0; i < d.size(); ++i) {
			if (d[i].size() >= max_len && comp(s, d[i])) {				//������ǰ�˳�
				if (d[i].size() >= max_len) {				//ֻ���볤�ȵ������ַ���
					sv.push_back(d[i]);
					max_len = d[i].size();
				}
			}
		}
		if (sv.size() == 0)
			return NULL;
		//��Ϊvector���ַ������ȵ��������Է����ҳ���󳤶���ͬ�Ĵ�
		for (auto iter = sv.rbegin(); iter != sv.rend(); ++iter) {	
			if (iter->size() == max_len) {
				ss.insert(*iter);
				continue;
			}
			break;
		}
		return *(ss.begin());

	}
};

//�Ƚ��ֵ��е��ַ����ܷ�ͨ�������ַ����ĵ�(O(n+k))
bool comp(const string& s, const string& d) {
	auto iter_s = s.begin();
	auto iter_d = d.begin();

	for (; iter_s != s.end() && iter_d != d.end();) {
		if (*iter_s != *iter_d) {
			++iter_s;
			continue;
		}
		++iter_s;
		++iter_d;
	}

	if (iter_d != d.end())
		return false;
	return true;
}