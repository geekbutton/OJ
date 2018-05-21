// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
378. 有序矩阵中第K小的元素

https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。
*/
/*利用堆求解，注意C++中只有优先队列即大端堆，本题要求求出第K小元素，因此注意索引的转换
时间复杂度
*/
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> iq;
		int num = matrix.size();
		int n = 1;
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				iq.push(matrix[i][j]);					//建堆(大端堆)
			}
		}
		while (n != num*num - k + 1) {					//一次推出前面的大数
			iq.pop();
			++n;
		}
		return iq.top();
	}
};
