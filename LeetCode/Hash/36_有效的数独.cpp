// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
36. 有效的数独
https://leetcode-cn.com/problems/valid-sudoku/description/

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

说明:
	一个有效的数独（部分已被填充）不一定是可解的。
	只需要根据以上规则，验证已经填入的数字是否有效即可。
	给定数独序列只包含数字 1-9 和字符 '.' 。
	给定数独永远是 9x9 形式的。
*/

/*整体思路是 :	设置三个vector包含map，分别代表行，列及3*3宫，遍历每一个元素，在对应三个
vector中设置map的值，map的key为九宫格的元素，value为元素出现的次数，一旦出现的次数大于2则
返回false，否则一直到所有元素遍历完成返回true。
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//设置三个vector表示行 列 宫的元素及其出现次数
		vector<unordered_map<char, int>> mv_row(9), mv_col(9), mv_patch(9);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char value = board[i][j];
				if (value != '.') {
					if (++mv_row[i][value] >= 2)
						return false;
					if (++mv_col[j][value] >= 2)
						return false;
					//根据行号和列号获取对应宫的索引
					int index = i / 3 * 3 + j / 3;
					if (++mv_patch[index][value] >= 2)
						return false;
				}
			}
		}
		return true;
	}
};