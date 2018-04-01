// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Insert a Node at the Tail of a Linked List

Input Format
You have to complete the Node* Insert(Node* head, int data) method. It takes two arguments: the head of the linked list and the integer to insert. You should not read any input from the stdin/console.

Output Format
Insert the new node at the tail and just return the head of the updated linked list. Do not print anything to stdout/console.
*/


/*
Insert Node at the end of a linked list
head pointer input could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Insert(Node *head, int data)
{
	// Complete this method
	if (head == NULL) {
		Node *temp_head = new Node;
		temp_head->data = data;
		temp_head->next = NULL;
		head = temp_head;
	}
	else {
		Node *current_head = head;
		while (current_head->next != NULL) {
			current_head = current_head->next;
		}
		Node *temp_head = new Node;
		temp_head->data = data;
		temp_head->next = NULL;
		current_head->next = temp_head;
	}
	return head;
}
