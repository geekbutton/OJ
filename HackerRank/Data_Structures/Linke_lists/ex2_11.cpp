// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Delete duplicate-value nodes from a sorted linked list

Input Format
You have to complete the Node* RemoveDuplicates(Node* head) method which takes one argument - the head of the sorted linked list. You should NOT read any input from stdin/console.

Output Format
Delete as few nodes as possible to ensure that no two nodes have the same data. Adjust the next pointers to ensure that the remaining nodes form a single sorted linked list. Then return the head of the sorted updated linked list. Do NOT print anything to stdout/console.

*/


/*
Remove all duplicate elements from a sorted linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* RemoveDuplicates(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method.
	Node *current_node = head;
	while (current_node != NULL) {
		Node *temp_node = current_node;
		while (temp_node->next != NULL && temp_node->data == temp_node->next->data) {
			temp_node = temp_node->next;
		}
		current_node->next = temp_node->next;
		current_node = current_node->next;
	}
	return head;
}

