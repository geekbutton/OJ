// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
138. ���ƴ����ָ�������

https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/

����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
Ҫ�󷵻�����������ȿ�����
*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
/*ע�⣬����Ҫ����Ƕ���������������˲��ܼ򵥵ظ���ָ�룬��Ӧ�ø���ָ�����Ϊ
�����������vector����������ԭ�����Ԫ�أ���ȷ��randomָ��ָ��Ľڵ�
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;

		vector<RandomListNode*> rv1, rv2;			//�ֱ𱣴�ԭʼ������������
		RandomListNode* result= new RandomListNode(head->label);	
		RandomListNode* current_s = result;
		RandomListNode* current = head->next;

		rv1.push_back(head);
		rv2.push_back(result);
		while (current) {						//����ԭ�����е�ֵ
			RandomListNode* temp = new RandomListNode(current->label);
			current_s->next = temp;
			if (current->random == NULL)		//��ԭ�����е�randomָ��ΪNULL����Ϊ���������ำֵNULL
				current_s->random == NULL;

			//����rv1,rv2��ע��rv2�ĸ�������current_s����֮��
			rv1.push_back(current);
			current_s = current_s->next;
			rv2.push_back(current_s);
			current = current->next;
		}
		//��ʼ���ݱȽ�randomָ����ԭ�����нڵ��ʵ��ָ�����ж�randomָ��Ӧ��ָ��Ľڵ��������е�����λ��
		for (int i = 0; i < rv1.size(); ++i) {
			RandomListNode* temp = rv1[i];
			RandomListNode* random_temp = temp->random;
			if (random_temp == NULL)
				continue;
			for (int j = 0; j < rv1.size(); ++j) {
				if (random_temp == rv1[j]) {			//ȷ��rv[i]��randomָ��ָ��rv[j]
					rv2[i]->random = rv2[j];			//��˿�������ĵ�i���ڵ��randomָ����Ӧָ�����j���ڵ�
					break;
				}
			}
		}
		return rv2[0];
	}
};
