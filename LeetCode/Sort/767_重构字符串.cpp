// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
767. �ع��ַ���
https://leetcode-cn.com/problems/reorganize-string/description/

����һ���ַ���S������Ƿ��������Ų����е���ĸ��ʹ�������ڵ��ַ���ͬ��
�����У����������еĽ�����������У����ؿ��ַ�����
*/

/*����˼·�� :	��ͳ���ַ����������ַ��󶨣�Ȼ����������У����ö������ȡ����Ƶ����ߵ��ַ���
ÿ�δӶ���ȡ��Ƶ����ߵ�ǰ����Ԫ�أ����������һ����������У��ظ��������ֱ�����в�������Ԫ�أ�
��ʱ���������ֻ��һ��Ԫ�أ�����Ԫ�ظ������ڵ���2�����Ȼ�޷��������⣬����ɹ�����������Ҫ����ַ�����
*/
class Solution {
public:
	string reorganizeString(string S) {
		unordered_map<char, int> im;
		for (auto x : S)
			++im[x];
		priority_queue<pair<int, char>> iq;
		for (auto iter = im.begin(); iter != im.end(); ++iter) {
			iq.push(pair<int,char>(iter->second,iter->first));
		}
		string result = S;
		int num = S.size();
		int index = 0;
		while (num) {
			//�ж϶���ʣ��Ԫ�ظ���
			if (iq.size() >= 2) {
				//ȡ��ǰ������ƵԪ�أ��������ü����ֱ��һ��
				auto temp_1 = iq.top();
				iq.pop();
				auto temp_2 = iq.top();
				iq.pop();
				//ע�⣬�����ִ���Ϊ0ʱ��������ѡ�
				--temp_1.first;
				--temp_2.first;
				result[index++] = temp_1.second;
				result[index++] = temp_2.second;
				if(temp_1.first)	iq.push(temp_1);
				if(temp_2.first)	iq.push(temp_2);
				num -= 2;
			}
			//�жϴ����������
			if (iq.size() == 1) {
				if (iq.top().first >= 2)
					return "";
				result[index] = iq.top().second;
				return result;	
			}
		}
		return result; 
	}
};