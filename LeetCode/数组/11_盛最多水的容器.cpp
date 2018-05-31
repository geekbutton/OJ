// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
11. ʢ���ˮ������
https://leetcode-cn.com/problems/container-with-most-water/description/

���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���� n ����ֱ�ߣ�ʹ�ô�ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)���ҳ����е������ߣ�
ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
*/

/*����˼·�� :	��������ָ��ֱ�ָ������ͷβ�����������Ȼ��ѡ��������ֱ���н϶���
����ָ�����м��ƶ�������������ظ��������֪������ָ��������
ע�����������ȡ������С�ߣ����ֻ�п��������ƶ���С��ָ�룬�������������ƶ��ϴ��ָ�롣
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;		//����ָ��ָ��ͷβ
		int maxarea = 0;
		while (i < j) {
			if ((j - i)*min(height[i], height[j]) > maxarea) {		//���㵱ǰ������
				maxarea = (j - i)*min(height[i], height[j]);
			}
			//��ѡ�϶̱��������ƶ�
			if (height[i] > height[j])
				--j;
			else
				++i;
		}
		return maxarea;
	}
};