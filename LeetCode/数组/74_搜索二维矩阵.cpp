// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
74. 搜索二维矩阵
https://leetcode-cn.com/problems/search-a-2d-matrix/description/

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
*/

/*整体思路是 :	因为数组每一行，每一列都是有序的，所以可以使用二分查找的方式来进行搜索。
首先从第一列开始搜索，搜索小于target的最大行索引(不存在，返回false)。再从0到该索引搜索
第一个也是唯一一个大于target的行索引(不存在，返回false)，再在该行上执行一次简单的二分查找
即可得到最终结果。
*/
int bs_row(int&, int&, int, vector<vector<int>>&, int);
bool bs(int, int, vector<int>&, int);
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size()==0)
			return false;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int row_l = 0, row_r = rows - 1;
		int col_l = 0, col_r = cols - 1;

		int flag = bs_row(row_l, row_r, 0, matrix, target);
		if (flag == 0)
			return false;
		if (flag == 1)
			return true;
		row_l = 0;
		flag = bs_row(row_l, row_r, cols - 1, matrix, target);
		if (flag == 0)
			return false;
		if (flag == 1)
			return true;
		return bs(0, col_r, matrix[row_r], target);
	}
};
//按列二分查找函数
int bs_row(int& l, int& r, int col, vector<vector<int>>& matrix, int target) {
	if (l > r) {
		//注意对r的处理，如果r小于0则说明所有数字均大于target则返回0
		//否则返回2
		if (r < 0)
			return 0;
		//if (matrix[r][col] < target)
		return 2;
	}
	int mid = (l + r) / 2;
	if (matrix[mid][col] == target)
		return 1;
	//根据col判断要进行的处理，如果为0则是找出最后一个小于target的行索引
	//如果col为最后一列，则是找出第一个大于target的行尾的索引
	if (col == 0) {
		if (matrix[mid][col] > target)
			r = mid - 1;
		else
			l = mid + 1;
		return bs_row(l, r, col, matrix, target);
	}
	else {
		if (matrix[mid][col] > target)
			return 2;
		else {
			l = mid + 1;
			return bs_row(l, r, col, matrix, target);
		}
	}
}
//简单的二分查找
bool bs(int l, int r, vector<int>& iv, int target) {
	if (l > r)
		return false;
	int mid = (l + r) / 2;
	if (iv[mid] == target)
		return true;
	if (iv[mid] > target)
		return bs(l, mid - 1, iv, target);
	else
		return bs(mid + 1, r, iv, target);
}