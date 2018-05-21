// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
215. �����еĵ�K�����Ԫ��

https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/

��δ������������ҵ��� k ������Ԫ�ء���ע�⣬
����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
*/

/*��Ҫ˼·�����ö������õ�K������Ԫ��
*/
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> iq;
		for (auto iter : nums) {
			iq.push(iter);
		}
		int n = 1;
		while (n != k) {
			iq.pop();
			++n;
		}
		return iq.top();
	}
};
