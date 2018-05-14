// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
143. ��������

https://leetcode-cn.com/problems/reorder-list/description/
����һ�������� L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·������һ��vector��������Ȼ���������ķ�ʽָ�����������˳��(Ӧ���и��õķ�ʽ)��
*/
class Solution {
public:
	void reorderList(ListNode* head) {
		vector<ListNode*> lv;
		ListNode* current = head;
		int num = 0;
		while (current) {				//���Ƚ������Ӧ������vector��
			lv.push_back(current);
			current = current->next;
			++num;
		}
		current = head;
		for (int i = 0; i < num/2; ++i) {
			current->next = lv[num - i - 1];	//����vector����ȷ����ǰ�ڵ����һ�������¸�Ԫ��
			current->next->next = lv[i + 1];
			if (num - i - 1 == i + 1)			//���ListNodeΪż�����������һ���ڵ�
				current->next->next = NULL;
			current = current->next->next;
		}
		if (num % 2) {							//���ڵ���Ϊ�������������һ���ڵ�
			current->next = NULL;
		}
	}
};