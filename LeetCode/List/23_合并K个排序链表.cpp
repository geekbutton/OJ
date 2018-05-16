// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
23. 合并K个排序链表

https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*主要思路：相当于两两有序链表的合并。两链表的合并可以通过添加一个头节点，但此处，因为无法保证
头节点的值一定是最小的，所以没有采用此种思路。而是分别比较头节点和后续节点从而合并。
*/
ListNode* Get_solution(ListNode*, ListNode*);
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return NULL;
		if (lists.size() == 1)
			return lists[0];
		ListNode* result = lists[0];						//两链表的合并可以通过添加一个头节点
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

	if (l2->val < l1->val) {				//检查头节点
		ListNode* temp = l2->next;
		l2->next = l1;
		l1 = l2;							//注意作为结果的l1的头节点的更新
		l2 = temp;							//更新第二个链表的头节点
	}

	ListNode* pre = l1;		
	ListNode* current1 = l1->next;
	ListNode* current2 = l2;

	while (current1 && current2) {			//比较头节点之后的其他节点
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