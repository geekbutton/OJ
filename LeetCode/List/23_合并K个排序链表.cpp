// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
23. �ϲ�K����������

https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*��Ҫ˼·���൱��������������ĺϲ���������ĺϲ�����ͨ�����һ��ͷ�ڵ㣬���˴�����Ϊ�޷���֤
ͷ�ڵ��ֵһ������С�ģ�����û�в��ô���˼·�����Ƿֱ�Ƚ�ͷ�ڵ�ͺ����ڵ�Ӷ��ϲ���
*/
ListNode* Get_solution(ListNode*, ListNode*);
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return NULL;
		if (lists.size() == 1)
			return lists[0];
		ListNode* result = lists[0];						//������ĺϲ�����ͨ�����һ��ͷ�ڵ�
		ListNode* pre = new ListNode();
		int index = 0;
		for (index = 0; index < lists.size(); ++index) {
			if (lists[index] == NULL)
				continue;
			result = lists[index];
			pre->next = result;
			break;
		}
		for (int i = index + 1; i < lists.size(); ++i) {
			result = Get_solution(result, lists[i]);
		}
		ListNode* head = pre->next;
		delete(pre);
		return result;
	}
};

ListNode* Get_solution(ListNode* l1, ListNode* l2) {
	if (l2 == NULL)
		return l1;

	if (l2->val < l1->val) {				//���ͷ�ڵ�
		ListNode* temp = l2->next;
		l2->next = l1;
		l1 = l2;							//ע����Ϊ�����l1��ͷ�ڵ�ĸ���
		l2 = temp;							//���µڶ��������ͷ�ڵ�
	}

	ListNode* pre = l1;		
	ListNode* current1 = l1->next;
	ListNode* current2 = l2;

	while (current1 && current2) {			//�Ƚ�ͷ�ڵ�֮��������ڵ�
		if (current2->val > pre->val && current2->val > current1->val) {
			pre = current1;
			current1 = current1->next;
			continue;
		}
		pre->next = current2;
		pre = pre->next;
		ListNode* temp = current2->next;
		current2->next = current1;
		current2 = temp;
	}
	if (current1 == NULL) {
		pre->next = current2;
	}

	return l1;
}