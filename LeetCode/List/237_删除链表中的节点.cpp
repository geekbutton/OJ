// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
237. 删除链表中的节点

https://leetcode-cn.com/problems/delete-node-in-a-linked-list/description/
编写一个函数，使其可以删除某个链表中给定的（非末尾的）节点，您将只被给予要求被删除的节点。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路：没有前驱就创造前驱。首先让node->next覆盖node，然后删除node->next
*/
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* temp = node->next;
		node->val = temp->val;				//注意这里的赋值，不能是node=node->next
		node->next = temp->next;			//那样将无法正确删除
		delete(temp);
	}
};