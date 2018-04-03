// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Inserting a Node Into a Sorted Doubly Linked List

Input Format

Input Format

Do not read any input from stdin. Hidden stub code reads in the following sequence of inputs and passes  and  to the method:

The first line contains an integer, , denoting the number of lists that will be checked. The subsequent lines describe the elements to insert into each list over two lines:

The first line contains an integer, , denoting the number of elements that will be inserted into the list.
The second line contains  space-separated integers describing the respective data values that your code must insert into the list during each call to the method.
Output Format

Do not print anything to stdout. Your method must return a reference to the  of the same list that was passed to it as a parameter. The custom checker for this challenge checks the list to ensure it hasn't been modified other than to properly insert the new Node in the correct location.

*/


/*
Insert Node in a doubly sorted linked list
After each insertion, the list should be sorted
Node is defined as
struct Node
{
int data;
Node *next;
Node *prev;
}
*/
Node* SortedInsert(Node *head, int data)
{
	// Complete this function
	// Do not write the main method. 
	Node *current_node = head;
	if (head == NULL) {
		Node *temp_node = new Node;
		temp_node->data = data;
		temp_node->next = NULL;
		temp_node->prev = NULL;
		head = temp_node;
		return head;
	}
	else {
		if (current_node != NULL && data > current_node->data) {
			Node *temp_node = SortedInsert(current_node->next, data);
			head->next = temp_node;
			temp_node->prev = head;
			return head;
		}
		Node *temp_node = new Node;
		temp_node->data = data;
		temp_node->next = current_node;
		head = temp_node;

		return head;
	}
}