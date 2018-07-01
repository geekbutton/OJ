// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
37. 解数独
https://leetcode-cn.com/problems/valid-sudoku/description/

编写一个程序，通过已填充的空格来解决数独问题。
一个数独的解法需遵循如下规则：
	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

Note:
	给定的数独序列只包含数字 1-9 和字符 '.' 。
	你可以假设给定的数独只有唯一解。
	给定数独永远是 9x9 形式的。
*/

/*整体思路是 :	设置三个vector<vector<bool>>用来存放每一行每一列每一宫中1-9是否存在的标志，
首先遍历整个九宫格，将对应标志位置1，同时记录待填充的元素位置。然后利用递归的想法，依次往
带填充的位置填入可能填入的元素(可能填入的元素通过上述三个vector的对应位判断)。
*/
bool sudoku(vector<vector<char>>&, const vector<vector<int>>&, int, vector<vector<bool>>&,
	vector<vector<bool>>&, vector<vector<bool>>&);
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> bv_row(9, vector<bool>(9)), bv_col(9, vector<bool>(9)), bv_patch(9, vector<bool>(9));
		vector<vector<int>> position;
		//首先记录每一行列宫已经出现的元素，将其对应在vector中置1
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char value = board[i][j];
				if (value == '.') {//同时记录待填充的元素位置
					position.push_back(vector<int>{i, j});
					continue;
				}
				bv_row[i][value - '0' - 1] = 1;
				bv_col[j][value - '0' - 1] = 1;
				int index = i / 3 * 3 + j / 3;
				bv_patch[index][value - '0' - 1] = 1;
			}
		}
		sudoku(board, position, 0, bv_row, bv_col, bv_patch);
		return;
	}
};

//递归程序实现
bool sudoku(vector<vector<char>>&board, const vector<vector<int>>& position, int index, vector<vector<bool>>& bv_row,
	 vector<vector<bool>>& bv_col, vector<vector<bool>>& bv_patch) {
	if (index == position.size())//如果已经处理了最后一个元素，则返回true
		return true;
	int x = position[index][0], y = position[index][1];	//根据position和index确定待插入位置坐标
	int temp_index = x / 3 * 3 + y / 3;
	for (int i = 0; i < 9; ++i) {
		//查找在行列宫中对应标志位都为0的元素，则其为可插入元素
		if (bv_row[x][i])
			continue;
		if (bv_col[y][i] || bv_patch[temp_index][i])
			continue;
		//对应位置1
		bv_row[x][i] = 1; bv_col[y][i] = 1; bv_patch[temp_index][i] = 1;
		board[x][y] = i + 1 + '0';	//更新board为对应元素
		if (sudoku(board, position, index + 1, bv_row, bv_col, bv_patch))	//继续迭代
			return true;	
		//为假则说明该元素不能插在该位置，因此对应位重新置0，继续下一个可能元素
		bv_row[x][i] = 0; bv_col[y][i] = 0; bv_patch[temp_index][i] = 0;	
	}
	return false;	
}