// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Get Node Value

Input Format
You have to complete the int GetNode(Node* head, int positionFromTail) method which takes two arguments - the head of the linked list and the position of the node from the tail. positionFromTail will be at least 0 and less than the number of nodes in the list. You should NOT read any input from stdin/console.

Constraints
Position will be a valid element in linked list.

Output Format
Find the node at the given position counting backwards from the tail. Then return the data contained in this node. Do NOT print anything to stdout/console.

*/


/*
Get Nth element from the end in a linked list of integers
Number of elements in the list will always be greater than N.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
int GetNode(Node *head, int positionFromTail)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 
	Node *current_node = head;
	Node *result_node = head;
	int index = 0;
	while (current_node != NULL) {						//current_node会循环到链表末尾
		current_node = current_node->next;
		if (index++ > positionFromTail) {				//result_node会比current_node少循环positionFromTail+1次
			result_node = result_node->next;			//所以最终会停在距结尾处positionFromTail的位置上
		}
	}
	return result_node->data;
}

