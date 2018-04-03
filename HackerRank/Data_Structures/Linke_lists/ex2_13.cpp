// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
Find Merge Point of Two Lists

Input Format

The FindMergeNode(Node*,Node*) method has two parameters,  and , which are the non-null head Nodes of two separate linked lists that are guaranteed to converge.
Do not read any input from stdin/console.

Output Format

Each Node has a data field containing an integer; return the integer data for the Node where the two lists converge.
Do not write any output to stdout/console.

*/


/*
Find merge point of two linked lists
Node is defined as
struct Node
{
int data;
Node* next;
}
*/
int FindMergeNode(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method. 
	Node *currentA = headA;
	Node *currentB = headB;
	while (currentA != currentB) {				//�����ϻ����ȱ���A��BȻ�����A��B�ķǹ�������
		if (currentA == NULL)					//��ʱ����ָ��������ͬ�Ĳ���������ڵ�һ������λ������
			currentA = headB;
		else currentA = currentA->next;

		if (currentB == NULL)
			currentB = headA;
		else currentB = currentB->next;
	}
	return currentA->data;
}