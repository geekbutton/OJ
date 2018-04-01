// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Insert a node at the head of a linked list

Input Format
You have to complete the Node* Insert(Node* head, int data) method which takes two arguments - the head of the linked list and the integer to insert. You should NOT read any input from stdin/console.

Output Format
Insert the new node at the head and return the head of the updated linked list. Do NOT print anything to stdout/console.
*/


/*
Insert Node at the begining of a linked list
Initially head pointer argument could be NULL for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head, int data)
{
	// Complete this method
	Node *temp_head = new Node;
	if (head == NULL) {
		temp_head->data = data;
		temp_head->next = NULL;
		head = temp_head;
		return head;
	}
	else {
		temp_head->data = data;
		temp_head->next = head;
		return temp_head;
	}
}
