// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
350. 两个数组的交集 II
https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/

给定两个数组，写一个方法来计算它们的交集。
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
跟进:
	如果给定的数组已经排好序呢？你将如何优化你的算法？
	如果 nums1 的大小比 nums2 小很多，哪种方法更优？
	如果nums2的元素存储在磁盘上，内存是有限的，你不能一次加载所有的元素到内存中，你该怎么办？
*/

/*整体思路是三种方法：
	1.	利用两个for循环遍历比较，时间复杂度O(n^2)，空间复杂度O(1)
	2.	先对两个数组排序，在利用一个for循环遍历，时间复杂度O(nlog(n))，空间复杂度O(1)
	3.	对较小长度数组建立哈希表，对较大长度数组依次在哈希表中查找，时间复杂度O(1)，空间复杂度
		O(min(n))(该方法非常适用于两个数组大小相差较大的情况下)
*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1 , vector<int>& nums2) {
		vector<int> result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		for (; i < nums1.size() && j < nums2.size();) {
			//注意判断划分的情况，排序后必须根据值得大小确定哪个索引前进
			if (nums1[i] < nums2[j]) {
				++i;
				continue;
			}
			else if (nums1[i] > nums2[j]) {
				++j;
				continue;
			}
			result.push_back(nums1[i]);
			++i;
			++j;
		}
		return result;
	}
};