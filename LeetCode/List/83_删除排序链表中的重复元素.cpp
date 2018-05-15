// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
83. 删除排序链表中的重复元素

https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是从head开始判断head及其下一个元素值是否相等，若不相等当前位置移动一位
若相等则删除当前节点的下一个节点，当前节点位置不变。
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* current = head;
		while (current && current->next) {
			if (current->val != current->next->val) {		//不相等则移动到下一个节点
				current = current->next;
				continue;
			}
			ListNode* temp = current->next;					//相等则改变next元素并删除
			current->next = current->next->next;
			delete(temp);									//删除next位置的节点
		}
		return head;
	}
};