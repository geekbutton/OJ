// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
71. ��·��
https://leetcode-cn.com/problems/simplify-path/description/

����һ���ĵ� (Unix-style) ����ȫ·���������·���򻯡�
*/

/*����˼·�� :	����getline����/�ָ�����ȡ�ַ����������ַ����жϲ���������ַ���Ϊ
�ջ�"."��ֱ������������ַ���Ϊ".."��ɾ��ǰһԪ�أ������������Ӹ��ַ���
*/
class Solution {
public:
	string simplifyPath(string path) {
		string res, tmp;
		vector<string> stk;				//����һ��vector����ÿ�ν��������ַ���������ɾ������
		stringstream ss(path);
		while (getline(ss, tmp, '/')) {
			if (tmp == "" or tmp == ".") continue;
			if (tmp == ".." and !stk.empty()) stk.pop_back();
			else if (tmp != "..") stk.push_back(tmp);
		}
		for (auto str : stk) res += "/" + str;
		return res.empty() ? "/" : res;
	}
};