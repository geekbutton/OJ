// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
445. ������� II

https://leetcode-cn.com/problems/add-two-numbers-ii/description/
���������ǿ����������������Ǹ��������������λλ������ʼλ�á�
���ǵ�ÿ���ڵ�ֻ�洢�������֡�����������ӻ᷵��һ���µ�����

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·�ǽ������е�Ԫ��ȡ������vector�У�Ȼ��������Ӧ��ӣ�����¼��λ��
ע��Խϳ�������Ԫ�صĴ���
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		
		int num1 = 0, num2 = 0;
		vector<int>iv1, iv2;
		ListNode* head1 = l1, *head2 = l2;
		while (l1) {
			iv1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			iv2.push_back(l2->val);
			l2 = l2->next;
		}
		num1 = iv1.size();
		num2 = iv2.size();
		ListNode* head = num1 > num2 ? head1 : head2;
		vector<int> result = num1 > num2 ? iv1 : iv2;
		int val_mod = 0;
		auto iterator = result.rbegin();
		for (--num1, --num2; num1 >= 0 && num2 >= 0; --num1, --num2, ++iterator) {	//������������Ĺ������ݲ���
			int val_1 = (iv1[num1] + iv2[num2] + val_mod) % 10;
			*iterator = val_1;
			val_mod = (iv1[num1] + iv2[num2] + val_mod) / 10;
		}
		for (iterator; iterator != result.rend(); ++iterator) {			//����ϳ�����Ķ��ಿ��
			int temp_value = 0;
			if (num1 >= 0) {											//���������
				int val_1 = (iv1[num1] + val_mod) % 10;
				*iterator = val_1; 
				val_mod = (iv1[num1] + val_mod) / 10;
				--num1;
			}
			else {
				int val_1 = (iv2[num2] + val_mod) % 10;
				*iterator = val_1;
				val_mod = (iv2[num2] + val_mod) / 10;
				--num2;
			}
		}

		ListNode* temp_head = new ListNode(val_mod);
		if (val_mod) {
			temp_head->val = val_mod;
			temp_head->next = head;
		}
		ListNode* current = head;
		int i = 0;
		while (current) {
			current->val = result[i];
			++i;
			current = current->next;
		}

		return (val_mod) ? temp_head : head;
	}
};