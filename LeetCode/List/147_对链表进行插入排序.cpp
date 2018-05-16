// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
147. 对链表进行插入排序

https://leetcode-cn.com/problems/insertion-sort-list/description/
对链表进行插入排序。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路：维系两个链表，一个表示最终排序的结果，一个表示剩余的数据链表，每次取出一个
剩余节点，将其插入已排序的链表中
*/
void Get_solution(ListNode*&, ListNode*&);
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* result = head;					//取原始链表头节点作为排序链表初始头
		
		head = head->next;							//当前head表示剩余节点链表的头
		result->next = NULL;						//注意一定要记住将排序链表的末尾next置为NULL
		while (head) {
			Get_solution(result, head);
		}
		return result;
	}
};

void Get_solution(ListNode*& result, ListNode*& head) {//注意传入参数，为指针的引用
	if (result->val > head->val) {					//首先比较头节点
		ListNode* temp = head->next;
		head->next = result;
		result = head;								//更新头节点
		head = temp;
		return;
	}
	ListNode* pre = result;
	ListNode* next = result->next;
	while (next) {
		if (pre->val < head->val && next->val < head->val) {
			pre = next;
			next = next->next;
			continue;
		}
		ListNode* temp = head->next;
		pre->next = head;
		head->next = next;
		head = temp;
		return;
	}
	pre->next = head;							//注意当元素被插入置排序链表末尾时，应更新尾元素指针为NULL
	head = head->next;
	pre->next->next = NULL;
	return;
}