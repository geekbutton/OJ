// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
61. ��ת����

https://leetcode-cn.com/problems/rotate-list/description/

����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·�Ǹ�������ĳ��Ⱥ�Kֵȷ��ʵ����Ҫƽ�Ƶĳ��ȣ�Ȼ���ҵ���ƽ�Ƶ�β����
������֯����ṹ��
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL)
			return head;
		int num = 1;
		ListNode* current = head;
		while (current->next) {				//ȷ��������
			++num;
			current = current->next;
		}
		int actual_k = k%num;				//ȷ��ʵ��ƽ�Ƴ���
		ListNode* last = current;			//���ƽ������β�ڵ�
		current = head;
		int index = 1;
		while (index != num - actual_k) {	//�ҵ���ƽ��β�����ǰһ�ڵ�
			current = current->next;
			++index;
		}
		last->next = head;					//β�����ĩβָ��ԭ�����ͷ
		head = current->next;				//ԭ�����ͷָ��β�����ͷ
		current->next = NULL;				//ԭ�����βָ��β�����β(��ΪNULL)

		return head;
	}
};
