// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
725. Split Linked List in Parts

https://leetcode-cn.com/problems/split-linked-list-in-parts/description/
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*ע�����⣬��Ŀ����˼�ǽ�һ������ƽ���ֶΣ�Ȼ��ÿһ���ֶε���Ԫ�ؽڵ����vector��
�����ǽ��ֶ��е����нڵ����vector��
*/
class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int num = 0;
		ListNode* current = root;
		while (current != NULL) {
			++num;
			current = current->next;
		}
		current = root;
		vector<ListNode*> result;
		while (current != NULL) {
			int size_iv = ceil((float)num / k);		//����ÿһ�εĳ��ȣ�ע��Ҫ��float��������ȡ��
			result.push_back(current);				//����Ӧ����Ԫ������vector
			for (int i = 0; i < size_iv; ++i) {
				ListNode* temp = current->next;	
				if (i == size_iv - 1) 
					current->next = NULL;			//����βԪ�ص�next�ÿ�
				current = temp;
			}
			num -= size_iv;
			--k;
		}
		while (current == NULL && k != 0) {			//�ж��Ƿ�ﵽָ������Ŀ�����û��
			result.push_back(NULL);					//�����ʣ����Ŀ��Ӧ�Ŀ�ָ��
			--k;
		}

		return result;
	}
};