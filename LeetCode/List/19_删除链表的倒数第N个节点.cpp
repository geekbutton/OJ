// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
19. ɾ������ĵ�����N���ڵ�

https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/

����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·�����õݹ�ķ����������һ��Ԫ�ؿ�ʼ��������������Ŀ��Ҫ��ʱ��ɾ����Ӧ�ڵ�
���ַ���ֻ��Ҫһ��ɨ�輴��ʵ�֡�
�������ȱ��������ȡ����ĳ��ȣ��ٸ��ݳ���ȷ��ɾ����Ԫ�ص�����������
*/
void Get_solution(ListNode*, int*, int);
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return NULL;
		ListNode* pre = new ListNode(0);			//����һ��ָ��head��ͷ�ڵ㣬���ڴ���ɾ��head�����
		pre->next = head;
		int index = 0;								//��������ֵ�����һ��Ԫ�ض�Ӧ����Ϊ1
		Get_solution(pre, &index,n);
		head = pre->next;
		delete(pre);
		return head;
	}
};

void Get_solution(ListNode* node, int* index,int n) {
	if (node->next) {
		Get_solution(node->next, index, n);
		if (*index == n) {					//��һ�η��صĵ�ǰ�ڵ��ǵ����ڶ����ڵ㣬����ɾ���Ľڵ��ǵ�ǰ�ڵ����һ�ڵ�
			ListNode* temp = node->next;
			node->next = temp->next;
			delete(temp);
		}//ע��ɾ���ɹ�����Ҫ��indexֵ�������һֱɾ����ͷ�ڵ�
		++((*index));
		return;
	}//�������һ��Ԫ��
	++(*index);
	return;
}