// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Insert a node at a specific position in a linked list

Input Format
You have to complete the Node* Insert(Node* head, int data, int position) method which takes three arguments - the head of the linked list, the integer to insert and the position at which the integer must be inserted. You should NOT read any input from stdin/console. position will always be between 0 and the number of the elements in the list (inclusive).

Output Format
Insert the new node at the desired position and return the head of the updated linked list. Do NOT print anything to stdout/console.

*/


/*
Insert Node at a given position in a linked list
head can be NULL
First element in the linked list is at position 0
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* InsertNth(Node *head, int data, int position)
{
	// Complete this method only
	// Do not write main function. 
	Node *temp_node = new Node;
	if (position == 0) {
		temp_node->data = data;
		temp_node->next = head;
		head = temp_node;
		return head;
	}
	else {
		Node *current_node = head;
		for (int i = 1; i < position; ++i) {
			current_node = current_node->next;
		}
		temp_node->data = data;
		temp_node->next = current_node->next;
		current_node->next = temp_node;
		return head;
	}
}