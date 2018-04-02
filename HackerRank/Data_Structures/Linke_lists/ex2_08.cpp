// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Compare two linked lists

Input Format
You have to complete the int CompareLists(Node* headA, Node* headB) method which takes two arguments - the heads of the two linked lists to compare. You should NOT read any input from stdin/console.

Output Format
Compare the two linked lists and return 1 if the lists are equal. Otherwise, return 0. Do NOT print anything to stdout/console.

*/


/*
Compare two linked lists A and B
Return 1 if they are identical and 0 if they are not.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
int CompareLists(Node *headA, Node* headB)
{
	// This is a "method-only" submission. 
	// You only need to complete this method 
	while (headA != NULL && headB != NULL) {
		if (headA->data != headB->data)
			return 0;
		else {
			headA = headA->next;
			headB = headB->next;
		}
	}
	if (headA == NULL && headB == NULL)
		return 1;
	else return 0;
}
