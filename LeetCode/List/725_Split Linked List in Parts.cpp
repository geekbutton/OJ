// Data_structures.cpp : 定义控制台应用程序的入口点。
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
/*注意题意，题目的意思是将一个链表平均分段，然后将每一个分段的首元素节点存入vector中
而不是将分段中的所有节点存入vector中
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
			int size_iv = ceil((float)num / k);		//计算每一段的长度，注意要是float除法向上取整
			result.push_back(current);				//将对应段首元素填入vector
			for (int i = 0; i < size_iv; ++i) {
				ListNode* temp = current->next;	
				if (i == size_iv - 1) 
					current->next = NULL;			//将段尾元素的next置空
				current = temp;
			}
			num -= size_iv;
			--k;
		}
		while (current == NULL && k != 0) {			//判断是否达到指定段数目，如果没有
			result.push_back(NULL);					//则添加剩余数目对应的空指针
			--k;
		}

		return result;
	}
};