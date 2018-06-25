// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
93. ��ԭIP��ַ
https://leetcode-cn.com/problems/restore-ip-addresses/description/

����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��
*/

/*����˼·�� :	��������������ȱ����ķ�����ʵ�֣�һ��IP��ַ�����ĸ��ֶΣ�ÿ���һ���ֶ�
��������������̳��ȣ��ڴ˷�Χ�ڱ�������ܵ�ȡֵ��
*/
void GetIP(string, string, vector<string>&, int);
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12 || s.size() < 4)
			return vector<string>();
		vector<string> result;
		int level = 4;
		string value;
		GetIP(s, value, result, level);
		return result;
	}
};

void GetIP(string s, string value, vector<string>& result, int level) {
	if (level == 1) {	//����IP��ַ�����һ���ֶ�
		//�����0��ͷ�������ֲ�Ϊ1���򲻺Ϸ�
		if (s.size() != 1 && s[0] == '0')
			return;
		if (s.size() == 3) {
			//�������Ϊ������Ҫ�ж��Ƿ�Ϸ�
			if ((s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0' > 255)
				return;
		}
		value += s;		//�Ϸ���������һ���ֶΣ�������������result��
		result.push_back(value);
		return;
	}
	int num = s.size();
	//���ݵ�ǰ�ַ����ĳ��Ⱥ�һ��IP�ֶ�����������С���ȣ����Ӧ�ֶεĳ��ȷ�Χ
	int i = max(1, num - (level - 1) * 3);		//��С����
	int max_len = min(3, num - (level - 1));	//��󳤶�
	for (i; i <= max_len; ++i) {
		//���ж��Ƿ�Ϸ�
		if (s[0] == '0' && i!=1)
			break;
		if (i == 3) {
			if ((s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0' > 255)
				return;
		}
		//�Ϸ������IP��ַ��ͬʱ�����ݹ������һ���ֶ�
		string temp = s.substr(0, i);
		value += temp + ".";
		GetIP(s.substr(i), value, result, level - 1);
		value.resize(value.size() - i - 1);		//�ǵ÷���ʱɾ���ղ���ӵ��ֶ�
	}
}