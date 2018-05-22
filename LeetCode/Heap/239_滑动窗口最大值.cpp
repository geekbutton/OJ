// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
239. �����������ֵ

https://leetcode-cn.com/problems/sliding-window-maximum/description/

����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ
��ֻ���Կ����ڻ������� k �ڵ����֡���������ÿ��ֻ�����ƶ�һλ��
���ػ����������ֵ��
����Լ��� k ������Ч�ģ�1 �� k �� ��������Ĵ�С�����������鲻Ϊ�ա�
*/

/*����˼·������˫�˶��н��д����Ա�֤ʱ�临�Ӷ�ΪO(n)������ԭ�����ж��½����Ԫ�أ�
����½����Ԫ�ش��ڶ��е�βԪ�أ���ΪԪ�س��ӣ�һֱ�����е�βԪ�ز�С�ڵ�ǰ�½���Ԫ�أ�
ͨ���÷�����֤�����е�Ԫ��Ϊ�ݼ������ÿ�εĴ������ֵΪ���еĶ�ͷԪ�ء�
ע�⣺Ӧ���ڶ����б���Ԫ����������������Ԫ�أ������ڻ������ڵĹ����н��޷��ж��Ƿ�Ӧ�ý�
��ͷ���ӡ�
*/
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> id_window;
		vector<int> result;
		if (nums.size() == 0)
			return result;
		for (int i = 0; i < k; ++i) {						//�ȴ���ǰK��Ԫ��
			while (id_window.size()) {
				if (nums[i] > nums[id_window.back()]) {
					id_window.pop_back();
					continue;
				}
				id_window.push_back(i);
				break;
			}
			if(id_window.size()==0)
				id_window.push_back(i);
		}
		result.push_back(nums[id_window.front()]);
		for (int i = k; i < nums.size(); ++i) {
			while (id_window.front() < i - k + 1)
				id_window.pop_front();
			while (id_window.size()) {
				if (nums[i] > nums[id_window.back()]) {
					id_window.pop_back();
					continue;
				}
				id_window.push_back(i);
				break;
			}
			if (id_window.size() == 0)
				id_window.push_back(i);
			result.push_back(nums[id_window.front()]);
		}
		return result;
	}
};
