// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
274. Hָ��
https://leetcode-cn.com/problems/h-index/description/

����һλ�о������ı����ô��������飨�����ô����ǷǸ�����������дһ��������������о��ߵ� h ָ����

hָ���Ķ���: ��һλ�� h ָ����ѧ�ߣ��������������� N ƪ������������ h ƪ���ģ�
�ֱ����������� h �Σ������ N - h ƪ����ÿƪ�����ô��������� h �Ρ�"
*/

/*����˼·�� :	�Ƚ����ô�����С��������Ȼ�����ô������κ͵�ǰʣ���������Ƚϣ�
���ҽ�����ǰ���ô������ڵ���ʣ�����ô���ʱ������Hָ���Ķ��塣���ص�һ�������������ֵ
��ΪHָ����
*/
class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int num = citations.size();
		for (int i = 0; i < citations.size(); ++i) {
			if (citations[i] >= num - i)
				return num - i;			//��Ϊʣ���������𽥼��٣����Ե�һ����������Hֵ��Ϊ���Hָ��
		}
		return 0;
	}
};