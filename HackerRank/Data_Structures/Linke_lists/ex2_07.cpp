// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Reverse a linked list

Input Format
You have to complete the Node* Reverse(Node* head) method which takes one argument - the head of the linked list. You should NOT read any input from stdin/console.

Output Format
Change the next pointers of the nodes that their order is reversed and return the head of the reversed linked list. Do NOT print anything to stdout/console.

*/


/*
Reverse a linked list and return pointer to the head
The input list will have at least one element
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Reverse(Node *head)
{
	// Complete this method
	Node *current_node = head;
	Node *temp_node = head;
	if (current_node != NULL) {
		if (current_node->next != NULL) {
			if (current_node->next->next != NULL) {
				temp_node = Reverse(current_node->next);
				current_node->next->next = current_node;
			}
			else {
				temp_node = current_node->next;
				current_node->next->next = current_node;
			}
		}
	}
	head->next = NULL;
	return temp_node;
}
