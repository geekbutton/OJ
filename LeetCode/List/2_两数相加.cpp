// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
2. 两数相加

https://leetcode-cn.com/problems/add-two-numbers/description/

给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，
它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是按链表顺序依次求和，将结果保存在较长的链表中。注意对最高位进位的处理。
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode* current1 = l1, *current2 = l2;
		int num1 = 1, num2 = 1;
		while (current1->next) {
			++num1;
			current1 = current1->next;
		}
		while (current2->next) {
			++num2;
			current2 = current2->next;
		}

		ListNode* result = (num1 > num2) ? l1 : l2;					//记录较长链表头作为结果链表头
		ListNode* last = (num1 > num2) ? current1 : current2;		//记录较长链表的尾前元素，便于最终处理最高位的进位
		current1 = (num1 > num2) ? l1 : l2;
		current2 = (num1 <= num2) ? l1 : l2;
		int flag = 0;
		//按链表顺序依次求解和，更新进位flag
		while (current2) {
			int value = (current1->val + current2->val + flag) % 10;
			flag = (current1->val + current2->val + flag) / 10;
			current1->val = value;

			current1 = current1->next;
			current2 = current2->next;
		}
		//处理较长链表的剩余数据
		while (current1 && flag) {
			int value = (current1->val + flag) % 10;
			flag = (current1->val + flag) / 10;
			current1->val = value;

			current1 = current1->next;
		}
		//处理超出链表长度的最高位的进位
		if (flag) {
			last->next = new ListNode(flag);
		}

		return result;
	}
};