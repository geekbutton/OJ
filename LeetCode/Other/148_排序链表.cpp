// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
148. 排序链表
https://leetcode-cn.com/problems/sort-list/description/

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
*/

/*整体思路是 :	考虑到这里的时间复杂度限制，因而考虑采用归并排序，但归并排序需要O(n)的空间
开销，但对于此处的链表可以采用in-place-sort的方式，因此符合题目的要求。
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* InsertionSort_list(ListNode*, ListNode*);
ListNode* Merge(ListNode*, ListNode*);
ListNode* MergeSort(ListNode*, int);
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		int num = 0;
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* current = head;
		while (current) {
			++num;
			current = current->next;
		}
		head = MergeSort(head, num);
		return head;
	}
};

//实现了两个有序链表的插入
ListNode* InsertionSort_list(ListNode* l, ListNode* r) {
	if (l->val > r->val) {
		ListNode* temp = r->next;
		r->next = l;
		l = r;
		r = temp;
	}
	ListNode* current_l = l->next, *current_r = r;
	ListNode* pre = l;
	while (current_l && current_r) {
		if (pre->next->val <= current_r->val && current_l->val <= current_r->val) {
			pre = pre->next;
			current_l = current_l->next;
			continue;
		}
		ListNode* temp = current_r->next;
		pre->next = current_r;
		current_r->next = current_l;
		current_r = temp;
		pre = pre->next;
	}
	if (current_r) {
		pre->next = current_r;
	}
	return l;
}
//归并排序的合并过程，调用的是两个有序链表合并的程序
ListNode* Merge(ListNode* l, ListNode* r) {
	ListNode* l_node = l, *r_node = r;
	ListNode* head = InsertionSort_list(l, r);
	ListNode* current = head;
	while (current->next) {
		current = current->next;
	}
	return head;
}
//归并排序的递归实现(之后可以考虑用非递归来实现归并排序)
ListNode* MergeSort(ListNode* head, int length) {
	if (length == 1) {
		head->next = NULL;
		return head;
	}
	int mid = (length) / 2 - 1;
	ListNode* r = head, *current = head;
	for (int i = 0; i < length - 1; ++i) {
		if (i == mid)
			r = current->next;
		current = current->next;
	}
	current->next = NULL;
	head = MergeSort(head, mid + 1);;
	r = MergeSort(r, length - mid - 1);
	head = Merge(head, r);
	return head;
}