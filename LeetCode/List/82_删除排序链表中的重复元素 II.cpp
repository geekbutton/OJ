// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
82. ɾ�����������е��ظ�Ԫ�� II

https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/

����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*��Ҫ˼·����ɾ���ظ��ڵ����һ������������㣬ͨ�����ñ�־��������ɾ����һ����
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* pre_head = new ListNode(0);		//�սڵ�ָ��head�����ں�������
		pre_head->next = head;
		ListNode* pre = head;						
		ListNode* pre_pre = pre_head;
		ListNode* current = head->next;
		int flag = 0;
		while (current) {
			if (pre->val == current->val) {			//ɾ�������ظ�Ԫ���еĺ�һ�������ñ�־��
				ListNode* temp = current;
				pre->next = temp->next;
				current = temp->next;
				flag = 1;
				delete(temp);
				continue;
			}
			if (flag) {								//ͨ����־���ж��Ƿ�ɾ����������Ԫ�صĵ�һ��
				flag = 0;
				pre_pre->next = pre->next;
				ListNode* temp = pre;
				pre = pre->next;
				current = pre->next;
				delete(temp);
				continue;
			}
			pre_pre = pre_pre->next;
			pre = pre->next;
			current = current->next;
		}
		if (flag) {								//ע�⣬������Ԫ���˳�whileʱ��Ҫ����ʱ�����һ��Ԫ���Ƿ�Ϊ�ظ�Ԫ��
			flag = 0;
			pre_pre->next = pre->next;
			ListNode* temp = pre;
			delete(temp);
		}

		head = pre_head->next;
		delete(pre_head);
		return head;
	}
};
