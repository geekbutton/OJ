// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
Cycle Detection

Input Format

Our hidden code checker passes the appropriate argument to your function. You are not responsible for reading any input from stdin.

Constraints

Output Format

If the list contains a cycle, your function must return true. If the list does not contain a cycle, it must return false. The binary integer corresponding to the boolean value returned by your function is printed to stdout by our hidden code checker.

*/


/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
struct Node {
int data;
struct Node* next;
}
*/

bool has_cycle(Node* head) {
	// Complete this function
	// Do not write the main method
	int index = 0;
	while (head != NULL) {
		head = head->next;
		++index;
		if (index > 100)
			return true;
	}
	return false;
}

//�����������⣬��������ڲٳ����ܲ���������ڻ������Ȼ������
bool has_cycle(Node* head) {
	// Complete this function
	// Do not write the main method
	Node *fast_node = head;
	Node *slow_node = head;
	int index = 1;
	while (fast_node != NULL) {					//�����������ٶȵ�����
		fast_node = fast_node->next;
		if (index % 2 == 0) {
			slow_node = slow_node->next;

		}
		++index;
		if (fast_node == slow_node)
			return true;
	}
	return false;
}