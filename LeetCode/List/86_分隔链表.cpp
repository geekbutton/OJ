// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
86. �ָ�����

https://leetcode-cn.com/problems/partition-list/description/
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·���ҳ���һ����XС�ĵ�ͱ�X��Ľڵ㣬�ֱ���Ϊ���������������ʼ�㣬Ȼ��ӱ�X��
�Ľڵ�����ͷ��ʼ������ÿ����������XС�Ľڵ㣬����ӵ�ǰλ���Ƴ������ڵ�һ������ĩβ��
*/
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		
		ListNode* less_node = head;
		ListNode* greater_node = head;
		ListNode* current = head->next;
		ListNode* pre = head;
		ListNode* result = head;


		//����������ֱ��õ�һ����XС�Ľڵ㼰���ڵ���X�Ľڵ�
		if (head->val < x) {								
			ListNode* temp = head->next;
			while (temp) {
				if (temp->val >= x) {
					greater_node = temp;
					less_node->next = greater_node;
					break;
				}
				pre = temp;
				less_node = temp;
				temp = temp->next;
			}
			if (temp == NULL)						//�������Σ��������ֵ����XС��ֱ�ӷ���ͷ
				return head;
			current = greater_node;					//���������ڵ�Ϊgreater_node
		}
		else if (head->val >= x) {
			ListNode* temp = head->next;
			while (temp) {
				if (temp->val < x) {
					less_node = temp;
					result = less_node;
					pre->next = temp->next;
					less_node->next = greater_node;
					break;
				}
				pre = temp;
				temp = temp->next;
			}
			current = greater_node;					//���������ڵ�Ϊgreater_node
		}

		while (current) {			
			if (current->val >= x) {
				pre = current;
				current = current->next;
				continue;
			}
			less_node->next = current;			//����less_node����
			//�൱��ɾ��ԭ��С��X�Ľڵ�
			ListNode* temp = current->next;
			pre->next = temp;					
			current->next = greater_node;		
			current = temp;						//���µ�ǰ����λ��

			less_node = less_node->next;		//����less_nodeλ�ã�ʼ��Ϊ��ǰ�����ĩβԪ��
		}

		return result;
	}
};