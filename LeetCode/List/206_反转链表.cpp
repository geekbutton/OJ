// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
206. 反转链表

https://leetcode-cn.com/problems/reverse-linked-list/description/
反转一个单链表。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*非常重要也非常常见，一共有两种实现方式，一种为迭代式的，一种为递归式的。
*/
class Solution {							//迭代式的方法
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* current = head->next;
		ListNode* pre = head;				//设置一个当前指针和其前驱指针
		while (pre && current) {
			ListNode* temp = current->next;	//记录当前指针的下一指针，因为之后会丢失
			current->next = pre;			//令当前指针指向其前向指针
			pre = current;					//更新其前驱
			current = temp;					//更新当前指针
		}
		head->next = current;				//设置原始头指针的next指针

		return pre;
	}
};

class Solution {							//递归实现方式
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)	
			return head;
		ListNode* root = reverseList(head->next);	//递归直至最后一个元素，返回该元素作为新的头指针
		head->next->next = head;				//反转当前元素与其下一个元素的指针(第一次为倒数第二个元素与最后一个元素)
		head->next = NULL;						//置当前元素的next指针为空
		return root;							//返回新的头元素
	}
};