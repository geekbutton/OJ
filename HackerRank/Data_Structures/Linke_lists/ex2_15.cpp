// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Reverse a doubly linked list

Input Format
You have to complete the Node* Reverse(Node* head) method which takes one argument - the head of the doubly linked list. You should NOT read any input from stdin/console.

Output Format
Change the next and prev pointers of all the nodes so that the direction of the list is reversed. Then return the head node of the reversed list. Do NOT print anything to stdout/console.

*/


/*
Reverse a doubly linked list, input list may also be empty
Node is defined as
struct Node
{
int data;
Node *next;
Node *prev;
}
*/
Node* Reverse(Node* head)
{
	// Complete this function
	// Do not write the main method. 
	Node *current_node = head;
	if (head == NULL)
		return NULL;
	while (current_node->next != NULL) {
		Node *temp_node = current_node->next;
		current_node->next = current_node->prev;
		current_node->prev = temp_node;
		current_node = current_node->prev;
	}
	current_node->next = current_node->prev;
	current_node->prev = NULL;
	return current_node;
}
