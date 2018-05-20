// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
138. 复制带随机指针的链表

https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的深度拷贝。
*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
/*注意，本题要求的是对链表进行深拷贝，因此不能简单地复制指针，而应该复制指针的行为
在这里，利用了vector容器来保存原链表的元素，以确定random指针指向的节点
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;

		vector<RandomListNode*> rv1, rv2;			//分别保存原始链表及拷贝链表
		RandomListNode* result= new RandomListNode(head->label);	
		RandomListNode* current_s = result;
		RandomListNode* current = head->next;

		rv1.push_back(head);
		rv2.push_back(result);
		while (current) {						//拷贝原链表中的值
			RandomListNode* temp = new RandomListNode(current->label);
			current_s->next = temp;
			if (current->random == NULL)		//若原链表中的random指针为NULL，即为拷贝链表亦赋值NULL
				current_s->random == NULL;

			//更新rv1,rv2，注意rv2的更新是在current_s更新之后
			rv1.push_back(current);
			current_s = current_s->next;
			rv2.push_back(current_s);
			current = current->next;
		}
		//开始根据比较random指针与原链表中节点的实际指针来判断random指针应该指向的节点在链表中的索引位置
		for (int i = 0; i < rv1.size(); ++i) {
			RandomListNode* temp = rv1[i];
			RandomListNode* random_temp = temp->random;
			if (random_temp == NULL)
				continue;
			for (int j = 0; j < rv1.size(); ++j) {
				if (random_temp == rv1[j]) {			//确定rv[i]的random指针指向rv[j]
					rv2[i]->random = rv2[j];			//因此拷贝链表的第i个节点的random指针亦应指向其第j个节点
					break;
				}
			}
		}
		return rv2[0];
	}
};
