// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
237. ɾ�������еĽڵ�

https://leetcode-cn.com/problems/delete-node-in-a-linked-list/description/
��дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ�ģ��ڵ㣬����ֻ������Ҫ��ɾ���Ľڵ㡣
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·��û��ǰ���ʹ���ǰ����������node->next����node��Ȼ��ɾ��node->next
*/
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* temp = node->next;
		node->val = temp->val;				//ע������ĸ�ֵ��������node=node->next
		node->next = temp->next;			//�������޷���ȷɾ��
		delete(temp);
	}
};