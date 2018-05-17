// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
92. ��ת���� II

https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·��������һ�������ͷ�ڵ�ָ��head�������Ϳ��Ա�����������(��ͷ��㿪ʼ��ת
�ʹӷ�ͷ�ڵ㿪ʼ��ת)������Ǵ�����ת�ڵ��ͷһ���ڵ���Ϊָʾ�����ӷ�ת�����ͷ�ڵ�
�ͽ���ת�����β�ڵ�����ĩβ��(Ҳ�����õݹ�ķ���)
*/
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL)
			return head;
		int count = 1;
		ListNode* pre_head = new ListNode(0);			//��Ǵ���ת����ڵ��ǰһ�ڵ�
		pre_head->next = head;
		ListNode* current = pre_head->next;
		ListNode* result = pre_head;

		while (count != m) {
			pre_head = current;
			current = current->next;
			++count;
		}
		ListNode* pre = current;						//��Ƿ�ת���������Ԫ��
		current = current->next;
		//��ת�������滻Ϊ�ݹ������ʽ
		while (count < n) {
			ListNode* temp = current->next;
			current->next = pre;
			pre = current;
			current = temp;
			++count;
		}
		pre_head->next->next = current;				//����ת�����β�ڵ㣬����һ������ת�ڵ�
		pre_head->next = pre;						//���ӷ�ת����֮ǰ��������
		pre_head = result;
		result = result->next;
		delete(pre_head);							//�ǵ��ͷ�new��ָ��

		return result;
	}
};