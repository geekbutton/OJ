// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
143. 重排链表

https://leetcode-cn.com/problems/reorder-list/description/
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是先用一个vector保存链表，然后用索引的方式指定链表的链接顺序(应该有更好的方式)。
*/
class Solution {
public:
	void reorderList(ListNode* head) {
		vector<ListNode*> lv;
		ListNode* current = head;
		int num = 0;
		while (current) {				//首先将链表对应保存如vector中
			lv.push_back(current);
			current = current->next;
			++num;
		}
		current = head;
		for (int i = 0; i < num/2; ++i) {
			current->next = lv[num - i - 1];	//根据vector索引确定当前节点的下一个及下下个元素
			current->next->next = lv[i + 1];
			if (num - i - 1 == i + 1)			//如果ListNode为偶数，处理最后一个节点
				current->next->next = NULL;
			current = current->next->next;
		}
		if (num % 2) {							//当节点数为奇数，处理最后一个节点
			current->next = NULL;
		}
	}
};