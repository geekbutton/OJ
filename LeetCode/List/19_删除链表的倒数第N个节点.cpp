// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
19. 删除链表的倒数第N个节点

https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是利用递归的方法，从最后一个元素开始计数，当满足题目是要求时，删除对应节点
这种方法只需要一次扫描即可实现。
还可以先遍历链表获取链表的长度，再根据长度确定删除的元素的正向索引。
*/
void Get_solution(ListNode*, int*, int);
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return NULL;
		ListNode* pre = new ListNode(0);			//设置一个指向head的头节点，便于处理删除head的情况
		pre->next = head;
		int index = 0;								//反向索引值，最后一个元素对应索引为1
		Get_solution(pre, &index,n);
		head = pre->next;
		delete(pre);
		return head;
	}
};

void Get_solution(ListNode* node, int* index,int n) {
	if (node->next) {
		Get_solution(node->next, index, n);
		if (*index == n) {					//第一次返回的当前节点是倒数第二个节点，可能删除的节点是当前节点的下一节点
			ListNode* temp = node->next;
			node->next = temp->next;
			delete(temp);
		}//注意删除成功后仍要加index值，否则会一直删除到头节点
		++((*index));
		return;
	}//返回最后一个元素
	++(*index);
	return;
}