// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
11. 盛最多水的容器
https://leetcode-cn.com/problems/container-with-most-water/description/

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，
使得它们与 x 轴共同构成的容器可以容纳最多的水。
*/

/*整体思路是 :	利用两个指针分别指向数组头尾，计算面积，然后选择两条垂直线中较短者
将其指针向中间移动，计算面积，重复这个过程知道两个指针相遇。
注意理解最大面积取决于最小边，因此只有可能向内移动最小边指针，而不可能向内移动较大边指针。
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;		//两个指针指向头尾
		int maxarea = 0;
		while (i < j) {
			if ((j - i)*min(height[i], height[j]) > maxarea) {		//计算当前最大面积
				maxarea = (j - i)*min(height[i], height[j]);
			}
			//挑选较短边向中心移动
			if (height[i] > height[j])
				--j;
			else
				++i;
		}
		return maxarea;
	}
};