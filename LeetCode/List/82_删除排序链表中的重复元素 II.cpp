// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
82. 删除排序链表中的重复元素 II

https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*主要思路是先删除重复节点除第一个点外的其他点，通过设置标志量来辅助删除第一个点
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* pre_head = new ListNode(0);		//空节点指向head，便于后续处理
		pre_head->next = head;
		ListNode* pre = head;						
		ListNode* pre_pre = pre_head;
		ListNode* current = head->next;
		int flag = 0;
		while (current) {
			if (pre->val == current->val) {			//删除两个重复元素中的后一个，并置标志量
				ListNode* temp = current;
				pre->next = temp->next;
				current = temp->next;
				flag = 1;
				delete(temp);
				continue;
			}
			if (flag) {								//通过标志量判断是否删除两个不等元素的第一个
				flag = 0;
				pre_pre->next = pre->next;
				ListNode* temp = pre;
				pre = pre->next;
				current = pre->next;
				delete(temp);
				continue;
			}
			pre_pre = pre_pre->next;
			pre = pre->next;
			current = current->next;
		}
		if (flag) {								//注意，当最后的元素退出while时，要检查此时的最后一个元素是否为重复元素
			flag = 0;
			pre_pre->next = pre->next;
			ListNode* temp = pre;
			delete(temp);
		}

		head = pre_head->next;
		delete(pre_head);
		return head;
	}
};
