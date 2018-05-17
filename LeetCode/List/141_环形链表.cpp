// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
141. ��������

https://leetcode-cn.com/problems/linked-list-cycle/description/
����һ�������ж��������Ƿ��л���
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*������������������˹������ܵ�˼�룬��������ָ�룬����ָ���ǰ���ٶȲ�ͬ������������
����������ָ��һ�������棬����һ��ָ�����ǰ�ߵ�NULL��
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* slower = head;					//����ָ��
		ListNode* faster = head->next;				//����ָ�룬����ָ����㲻ͬ
		while (slower!=faster) {
			//�ж��Ƿ����ָ���ߵ���NULL
			if (faster->next == NULL || faster->next->next==NULL)
				return false;
			slower = slower->next;					//����ָ��һ���ƶ�һ��λ��
			faster = faster->next->next;			//����ָ��һ���ƶ�����λ��

		}

		return true;
	}
};