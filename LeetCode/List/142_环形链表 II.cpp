// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
142. �������� II

https://leetcode-cn.com/problems/linked-list-cycle-ii/description/

����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
˵�����������޸ĸ���������
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*��Ҫ˼�������ÿ���ָ���ж��Ƿ��л���������λ������ָ�������ĵ㡣���������ѧ�Ƶ���֪��
�����㵽���ĵ�һ���ڵ�ľ����������ͷ���뻷��ľ��룬��ʱ����������ָ����һ�������뻷��������
*/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;

		ListNode* fast = head;
		ListNode* slow = head;
		
		while (fast->next && fast->next->next) {		//��ָ������ָ���ٶȵ�����
			slow = slow->next;
			fast = fast->next->next;
			if (slow != fast)		
				continue;
			//�ҵ��������㣬��ָ��������㿪ʼ����ָ���ͷ��ʼ����ͬ���ٶ�ǰ��
			fast = head;			
			while (slow != fast) {
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
		return NULL;
	}
};