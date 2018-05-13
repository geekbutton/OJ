// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
24. �������������еĽڵ�

https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
����һ���������������������ڵĽڵ㣬�����ؽ����������
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* Get_solution(ListNode*);

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* current = head;
		return Get_solution(head);
		
	}
};

//���õ����ķ�ʽ���
ListNode* Get_solution(ListNode* current) {
	//�ж��Ƿ�������Ԫ��
	if (current != NULL && current->next != NULL) {
		ListNode* result = current->next;		//����У��򱣴�ڶ���Ԫ��Ϊ���ؽ��
		ListNode* temp = current->next->next;
		current->next->next = current;
		current->next = Get_solution(temp);		//�趨��һ��Ԫ�ص�nextֵ������ǰһ������
		return result;							//���һ����������
	}
	return current;				//���û������Ԫ�أ���ֱ�ӷ���
}