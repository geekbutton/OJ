// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
160. �ཻ����

https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*�ǳ����͵Ŀ��⣬��Ҫ˼·��������������н��㣬�����A�����B������B�����Aʱһ��������
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* head1 = headA, *head2 = headB;
		if (headA == NULL || headB == NULL)
			return NULL;
		int count = 3;						//�����˳�����������ֱ������AB���������û����������˵�����ཻ
		while (count) {
			while (head1 && head2) {
				if (head1 == head2)		//������ֱ�ӷ���
					return head1;
				head1 = head1->next;
				head2 = head2->next;
			}
			if (head1 == NULL) {		//A��������B��ʼ����
				head1 = headB;
				--count;
			}
			else if (head2 == NULL) {	//B��������A��ʼ����
				head2 = headA;
				--count;
			}
		}

		return NULL;					//ִ�е��ô�˵�������ڽ��㣬���ؿ�
	}
};