// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Print in Reverse

Input Format
You have to complete the void ReversePrint(Node* head) method which takes one argument - the head of the linked list. You should NOT read any input from stdin/console.

Output Format
Print the elements of the linked list in reverse order to stdout/console (using printf or cout) , one per line.

*/


/*
Print elements of a linked list in reverse order as standard output
head pointer could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
void ReversePrint(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 
	if (head != NULL) {
		ReversePrint(head->next);
		cout << head->data << endl;
	}
}
