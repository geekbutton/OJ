// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Delete a Node

Input Format
You have to complete the Node* Delete(Node* head, int position) method which takes two arguments - the head of the linked list and the position of the node to delete. You should NOT read any input from stdin/console. position will always be at least 0 and less than the number of the elements in the list.

Output Format
Delete the node at the given position and return the head of the updated linked list. Do NOT print anything to stdout/console.

*/


/*
Delete Node at a given position in a linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Delete(Node *head, int position)
{
	// Complete this method
	if (position == 0) {
		Node *temp_head = head;
		head = head->next;
		free(temp_head);
		return head;
	}
	else {
		Node *current_node = head;
		for (int i = 1; i < position; ++i) {
			current_node = current_node->next;
		}
		Node *temp = current_node->next;
		current_node->next = temp->next;
		free(temp);
		return head;
	}
}
