// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
203. 删除链表中的节点

https://leetcode-cn.com/problems/remove-linked-list-elements/description/
删除链表中等于给定值 val 的所有节点。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*注意本题要求的是删除所有等于val的节点。首先判断头节点，如果头节点不等于则判断后续节点
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return NULL;
		while (head->val == val) {					//判断头节点是否等于val,若是则更新头节点
			ListNode* temp = head;
			head = head->next;
			delete(temp);
			if (head == NULL)
				return NULL;
		}
		ListNode* current = head;	
		while (current->next) {					//判断头节点之后的节点
			if (current->next->val != val) {	//不等于则更新至后一节点
				current = current->next;
				continue;
			}
			ListNode* temp = current->next;		//若等于更新current.next节点，删除原next节点
			current->next = temp->next;
			delete(temp);
		}
		return head;
	}
};