// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
92. 反转链表 II

https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路：先设置一个额外的头节点指向head，这样就可以避免分两种情况(从头结点开始反转
和从非头节点开始反转)处理，标记处待反转节点的头一个节点作为指示以连接反转链表的头节点
和将反转链表的尾节点连至末尾。(也可以用递归的方法)
*/
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL)
			return head;
		int count = 1;
		ListNode* pre_head = new ListNode(0);			//标记待反转链表节点的前一节点
		pre_head->next = head;
		ListNode* current = pre_head->next;
		ListNode* result = pre_head;

		while (count != m) {
			pre_head = current;
			current = current->next;
			++count;
		}
		ListNode* pre = current;						//标记反转链表的两个元素
		current = current->next;
		//反转链表，可替换为递归调用形式
		while (count < n) {
			ListNode* temp = current->next;
			current->next = pre;
			pre = current;
			current = temp;
			++count;
		}
		pre_head->next->next = current;				//处理反转链表的尾节点，即第一个待反转节点
		pre_head->next = pre;						//连接反转链表到之前的链表上
		pre_head = result;
		result = result->next;
		delete(pre_head);							//记得释放new的指针

		return result;
	}
};