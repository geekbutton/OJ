// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
79. 单词搜索
https://leetcode-cn.com/problems/word-search/description/

给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。
*/

/*整体思路是 :	暴力搜索，注意设置一个使用标志位，以避免重复使用元素。
*/
void find_word(int, int, vector<vector<char>>&, int, string&, int&, vector<int>&);
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int rows = board.size();
		int cols = board[0].size();
		int index = 0;
		int result = 0;
		vector<vector<int>> flag_use(rows,vector<int>(cols,0));			//使用标志位
		//找到第一个等于string[0]的元素位置，以其为起点递归查找
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (board[i][j] != word[index])
					continue;
				flag_use[i][j] = 1;
				find_word(i, j, board, index + 1, word, result, flag_use);
				if (result)
					return result;
				flag_use[i][j] = 0;
			}
		}
		return result;
	}
};

void find_word(int l, int r, vector<vector<char>>& board, int index, string& word, int& flag, vector<vector<int>>& use) {
	//一直到最后都相等，则另flag为1
	if (index == word.size()) {
		flag = 1;
		return;
	}
	char value = word[index];
	//从上下左右四个方向进行查找，要注意判断元素的重复使用问题
	if (l != 0 && !flag) {					//上
		if (board[l - 1][r] == value && !use[l - 1][r]) {
			use[l - 1][r] = 1;				//先置1，表示已使用
			find_word(l - 1, r, board, index + 1, word, flag, use);
			if (!flag)					//如果flag为0，说明选择该元素无法组成指定单词，应查找其他元素
				use[l - 1][r] = 0;		//因此，将其重新置0，表示未使用
			else
				return;
		}
	}
	if (l != board.size() - 1 && !flag && !use[l + 1][r]) {
		if (board[l + 1][r] == value) {		//下
			use[l + 1][r] = 1;
			find_word(l + 1, r, board, index + 1, word, flag, use);
			if (!flag)
				use[l + 1][r] = 0;
			else
				return;
		}
	}
	if (r != 0 && !flag && !use[l][r - 1]) {
		if (board[l][r - 1] == value) {		//左
			use[l][r - 1] = 1;
			find_word(l, r - 1, board, index + 1, word, flag, use);
			if (!flag)
				use[l][r - 1] = 0;
			else
				return;
		}
	}
	if (r != board[0].size() && !flag && !use[l][r + 1]) {
		if (board[l][r + 1] == value) {		//右
			use[l][r + 1] = 1;
			find_word(l, r + 1, board, index + 1, word, flag, use);
			if (!flag)
				use[l][r + 1] = 0;
			else
				return;
		}
	}

}