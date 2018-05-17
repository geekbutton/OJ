// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
86. 分隔链表

https://leetcode-cn.com/problems/partition-list/description/
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是找出第一个比X小的点和比X大的节点，分别作为两个链表分区的起始点，然后从比X大
的节点链表头开始搜索，每次搜索到比X小的节点，将其从当前位置移除，放于第一个链表末尾。
*/
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		
		ListNode* less_node = head;
		ListNode* greater_node = head;
		ListNode* current = head->next;
		ListNode* pre = head;
		ListNode* result = head;


		//分两种情况分别获得第一个比X小的节点及大于等于X的节点
		if (head->val < x) {								
			ListNode* temp = head->next;
			while (temp) {
				if (temp->val >= x) {
					greater_node = temp;
					less_node->next = greater_node;
					break;
				}
				pre = temp;
				less_node = temp;
				temp = temp->next;
			}
			if (temp == NULL)						//特殊情形：如果所有值都比X小，直接返回头
				return head;
			current = greater_node;					//更新搜索节点为greater_node
		}
		else if (head->val >= x) {
			ListNode* temp = head->next;
			while (temp) {
				if (temp->val < x) {
					less_node = temp;
					result = less_node;
					pre->next = temp->next;
					less_node->next = greater_node;
					break;
				}
				pre = temp;
				temp = temp->next;
			}
			current = greater_node;					//更新搜索节点为greater_node
		}

		while (current) {			
			if (current->val >= x) {
				pre = current;
				current = current->next;
				continue;
			}
			less_node->next = current;			//更新less_node链表
			//相当于删除原来小于X的节点
			ListNode* temp = current->next;
			pre->next = temp;					
			current->next = greater_node;		
			current = temp;						//更新当前搜索位置

			less_node = less_node->next;		//更新less_node位置，始终为当前链表的末尾元素
		}

		return result;
	}
};