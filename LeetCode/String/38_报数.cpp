// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
38. ����
https://leetcode-cn.com/problems/count-and-say/description/

��Ŀ������������
*/

/*����˼·�� :	ûʲô��˵�ģ�������д�����ʾ���ͳ������Ԫ�صĸ��������Ӧ����Ԫ�ء�
*/
string Fucking_count_and_Funcking_say(const string&);
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		string result = "1";
		--n;
		while (n--) {
			result = Fucking_count_and_Funcking_say(result);
		}
		return result;
	}
};

string Fucking_count_and_Funcking_say(const string& value) {
	string result;
	int count = 1;
	char temp = value[0];
	if (value.size() == 1) {
		return "11";
	}
	int i = 1;
	for (; i < value.size(); ++i) {
		if (value[i] == temp) {
			++count;
			continue;
		}
		result += to_string(count);
		result.push_back(temp);
		count = 1;
		temp = value[i];
	}
	if (value[i-1] == temp) {
		result += to_string(count);
		result.push_back(temp);
	}
	return result;
}