// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Merge two sorted linked lists

Input Format
You have to complete the Node* MergeLists(Node* headA, Node* headB) method which takes two arguments - the heads of the two sorted linked lists to merge. You should NOT read any input from stdin/console.

Output Format
Change the next pointer of individual nodes so that nodes from both lists are merged into a single list. Then return the head of this merged list. Do NOT print anything to stdout/console.

*/


/*
Merge two sorted lists A and B as one linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* MergeLists(Node *headA, Node* headB)
{
	// This is a "method-only" submission. 
	// You only need to complete this method
	if (headA == NULL && headB == NULL)
		return NULL;
	else if (headA == NULL)
		return headB;
	else if (headB == NULL)
		return headA;
	else {
		Node *head = headA->data < headB->data ? headA : headB;
		Node *temp_head = head;
		if (headA->data < headB->data) {
			temp_head = MergeLists(headA->next, headB);
		}
		else {
			temp_head = MergeLists(headA, headB->next);
		}
		head->next = temp_head;
		return head;
	}
}

