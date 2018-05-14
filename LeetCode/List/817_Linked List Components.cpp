// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
817. Linked List Components

https://leetcode-cn.com/problems/linked-list-components/description/
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·�Ǵ�ListNode��head��ʼ�����ң����head������G�У���head->nextҲ������G�оͼ���Ѱ��
�������²��Ҹ�Ԫ�أ����ý����һ��
*/
class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		int result = 0;
		ListNode* current = head;
		while (current != NULL) {
			auto iterator = find(G.begin(), G.end(), current->val);
			if (iterator != G.end()) {
				++result;								//����ڵ������G�У�������1
				current = current->next;
				while (current != NULL) {				//�жϽڵ�ĺ����ڵ��Ƿ������G��
					auto iterator2 = find(G.begin(), G.end(), current->val);
					if (iterator2 != G.end()) {			//������ֱ���ж���һ���ڵ�
						current = current->next;
						continue;
					}
					break;								//�����˳���ǰѭ������ʼ������һ����ʼԪ
				}
				if (current)							//�ж�һ��current�Ƿ����ߵ�����ĩβ
					continue;							//�����˳��������������
				break;
			}
			current = current->next;					//δ��G���ҵ���Ӧ�ڵ㣬������һ��
		}

		return result;
	}
};