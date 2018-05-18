// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
2. �������

https://leetcode-cn.com/problems/add-two-numbers/description/

���������ǿ���������ʾ�����Ǹ�������λ����������ʽ�洢��
���ǵ�ÿ���ڵ�ֻ�洢�������֡���������ӷ���һ���µ�����
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·�ǰ�����˳��������ͣ�����������ڽϳ��������С�ע������λ��λ�Ĵ���
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode* current1 = l1, *current2 = l2;
		int num1 = 1, num2 = 1;
		while (current1->next) {
			++num1;
			current1 = current1->next;
		}
		while (current2->next) {
			++num2;
			current2 = current2->next;
		}

		ListNode* result = (num1 > num2) ? l1 : l2;					//��¼�ϳ�����ͷ��Ϊ�������ͷ
		ListNode* last = (num1 > num2) ? current1 : current2;		//��¼�ϳ������βǰԪ�أ��������մ������λ�Ľ�λ
		current1 = (num1 > num2) ? l1 : l2;
		current2 = (num1 <= num2) ? l1 : l2;
		int flag = 0;
		//������˳���������ͣ����½�λflag
		while (current2) {
			int value = (current1->val + current2->val + flag) % 10;
			flag = (current1->val + current2->val + flag) / 10;
			current1->val = value;

			current1 = current1->next;
			current2 = current2->next;
		}
		//����ϳ������ʣ������
		while (current1 && flag) {
			int value = (current1->val + flag) % 10;
			flag = (current1->val + flag) / 10;
			current1->val = value;

			current1 = current1->next;
		}
		//�����������ȵ����λ�Ľ�λ
		if (flag) {
			last->next = new ListNode(flag);
		}

		return result;
	}
};