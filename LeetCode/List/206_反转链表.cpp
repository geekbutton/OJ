// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
206. ��ת����

https://leetcode-cn.com/problems/reverse-linked-list/description/
��תһ��������
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*�ǳ���ҪҲ�ǳ�������һ��������ʵ�ַ�ʽ��һ��Ϊ����ʽ�ģ�һ��Ϊ�ݹ�ʽ�ġ�
*/
class Solution {							//����ʽ�ķ���
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* current = head->next;
		ListNode* pre = head;				//����һ����ǰָ�����ǰ��ָ��
		while (pre && current) {
			ListNode* temp = current->next;	//��¼��ǰָ�����һָ�룬��Ϊ֮��ᶪʧ
			current->next = pre;			//�ǰָ��ָ����ǰ��ָ��
			pre = current;					//������ǰ��
			current = temp;					//���µ�ǰָ��
		}
		head->next = current;				//����ԭʼͷָ���nextָ��

		return pre;
	}
};

class Solution {							//�ݹ�ʵ�ַ�ʽ
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)	
			return head;
		ListNode* root = reverseList(head->next);	//�ݹ�ֱ�����һ��Ԫ�أ����ظ�Ԫ����Ϊ�µ�ͷָ��
		head->next->next = head;				//��ת��ǰԪ��������һ��Ԫ�ص�ָ��(��һ��Ϊ�����ڶ���Ԫ�������һ��Ԫ��)
		head->next = NULL;						//�õ�ǰԪ�ص�nextָ��Ϊ��
		return root;							//�����µ�ͷԪ��
	}
};