// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
147. ��������в�������

https://leetcode-cn.com/problems/insertion-sort-list/description/
��������в�������
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·��άϵ��������һ����ʾ��������Ľ����һ����ʾʣ�����������ÿ��ȡ��һ��
ʣ��ڵ㣬��������������������
*/
void Get_solution(ListNode*&, ListNode*&);
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* result = head;					//ȡԭʼ����ͷ�ڵ���Ϊ���������ʼͷ
		
		head = head->next;							//��ǰhead��ʾʣ��ڵ������ͷ
		result->next = NULL;						//ע��һ��Ҫ��ס�����������ĩβnext��ΪNULL
		while (head) {
			Get_solution(result, head);
		}
		return result;
	}
};

void Get_solution(ListNode*& result, ListNode*& head) {//ע�⴫�������Ϊָ�������
	if (result->val > head->val) {					//���ȱȽ�ͷ�ڵ�
		ListNode* temp = head->next;
		head->next = result;
		result = head;								//����ͷ�ڵ�
		head = temp;
		return;
	}
	ListNode* pre = result;
	ListNode* next = result->next;
	while (next) {
		if (pre->val < head->val && next->val < head->val) {
			pre = next;
			next = next->next;
			continue;
		}
		ListNode* temp = head->next;
		pre->next = head;
		head->next = next;
		head = temp;
		return;
	}
	pre->next = head;							//ע�⵱Ԫ�ر���������������ĩβʱ��Ӧ����βԪ��ָ��ΪNULL
	head = head->next;
	pre->next->next = NULL;
	return;
}