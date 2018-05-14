// Data_structures.cpp : 定义控制台应用程序的入口点。
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
/*整体思路是从ListNode的head开始往后找，如果head存在于G中，而head->next也存在于G中就继续寻找
否则重新查找该元素，并置结果加一。
*/
class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		int result = 0;
		ListNode* current = head;
		while (current != NULL) {
			auto iterator = find(G.begin(), G.end(), current->val);
			if (iterator != G.end()) {
				++result;								//如果节点存在于G中，则结果加1
				current = current->next;
				while (current != NULL) {				//判断节点的后续节点是否存在于G中
					auto iterator2 = find(G.begin(), G.end(), current->val);
					if (iterator2 != G.end()) {			//存在则直接判断下一个节点
						current = current->next;
						continue;
					}
					break;								//否则退出当前循环，开始查找下一个开始元
				}
				if (current)							//判断一下current是否已走到链表末尾
					continue;							//是则退出，否则继续查找
				break;
			}
			current = current->next;					//未在G中找到对应节点，继续下一个
		}

		return result;
	}
};