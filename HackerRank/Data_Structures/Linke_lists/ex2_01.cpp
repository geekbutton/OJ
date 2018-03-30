// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Print the Elements of a Linked List

Input Format

The void Print(Node* head) method takes the head node of a linked list as a parameter. Each struct Node has a data field (which stores integer data) and a next field (which points to the next element in the list).

Note: Do not read any input from stdin/console. Each test case calls the Print method individually and passes it the head of a list.

Output Format

Print the integer data for each element of the linked list to stdout/console (e.g.: using printf, cout, etc.). There should be one element per line.
*/


/*
Print elements of a linked list on console
head pointer input could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
void Print(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 
	if (head != NULL) {
		cout << head->data << endl;
		Print(head->next);
	}
}
