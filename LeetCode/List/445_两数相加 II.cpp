// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
445. 两数相加 II

https://leetcode-cn.com/problems/add-two-numbers-ii/description/
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*总体思路是将链表中的元素取出放于vector中，然后两两对应相加，并记录进位。
注意对较长链表多出元素的处理。
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		
		int num1 = 0, num2 = 0;
		vector<int>iv1, iv2;
		ListNode* head1 = l1, *head2 = l2;
		while (l1) {
			iv1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			iv2.push_back(l2->val);
			l2 = l2->next;
		}
		num1 = iv1.size();
		num2 = iv2.size();
		ListNode* head = num1 > num2 ? head1 : head2;
		vector<int> result = num1 > num2 ? iv1 : iv2;
		int val_mod = 0;
		auto iterator = result.rbegin();
		for (--num1, --num2; num1 >= 0 && num2 >= 0; --num1, --num2, ++iterator) {	//处理两个链表的公共数据部分
			int val_1 = (iv1[num1] + iv2[num2] + val_mod) % 10;
			*iterator = val_1;
			val_mod = (iv1[num1] + iv2[num2] + val_mod) / 10;
		}
		for (iterator; iterator != result.rend(); ++iterator) {			//处理较长链表的多余部分
			int temp_value = 0;
			if (num1 >= 0) {											//分情况处理
				int val_1 = (iv1[num1] + val_mod) % 10;
				*iterator = val_1; 
				val_mod = (iv1[num1] + val_mod) / 10;
				--num1;
			}
			else {
				int val_1 = (iv2[num2] + val_mod) % 10;
				*iterator = val_1;
				val_mod = (iv2[num2] + val_mod) / 10;
				--num2;
			}
		}

		ListNode* temp_head = new ListNode(val_mod);
		if (val_mod) {
			temp_head->val = val_mod;
			temp_head->next = head;
		}
		ListNode* current = head;
		int i = 0;
		while (current) {
			current->val = result[i];
			++i;
			current = current->next;
		}

		return (val_mod) ? temp_head : head;
	}
};