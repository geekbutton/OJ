// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
79. ��������
https://leetcode-cn.com/problems/word-search/description/

����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ�
���С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
*/

/*����˼·�� :	����������ע������һ��ʹ�ñ�־λ���Ա����ظ�ʹ��Ԫ�ء�
*/
void find_word(int, int, vector<vector<char>>&, int, string&, int&, vector<int>&);
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int rows = board.size();
		int cols = board[0].size();
		int index = 0;
		int result = 0;
		vector<vector<int>> flag_use(rows,vector<int>(cols,0));			//ʹ�ñ�־λ
		//�ҵ���һ������string[0]��Ԫ��λ�ã�����Ϊ���ݹ����
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
	//һֱ�������ȣ�����flagΪ1
	if (index == word.size()) {
		flag = 1;
		return;
	}
	char value = word[index];
	//�����������ĸ�������в��ң�Ҫע���ж�Ԫ�ص��ظ�ʹ������
	if (l != 0 && !flag) {					//��
		if (board[l - 1][r] == value && !use[l - 1][r]) {
			use[l - 1][r] = 1;				//����1����ʾ��ʹ��
			find_word(l - 1, r, board, index + 1, word, flag, use);
			if (!flag)					//���flagΪ0��˵��ѡ���Ԫ���޷����ָ�����ʣ�Ӧ��������Ԫ��
				use[l - 1][r] = 0;		//��ˣ�����������0����ʾδʹ��
			else
				return;
		}
	}
	if (l != board.size() - 1 && !flag && !use[l + 1][r]) {
		if (board[l + 1][r] == value) {		//��
			use[l + 1][r] = 1;
			find_word(l + 1, r, board, index + 1, word, flag, use);
			if (!flag)
				use[l + 1][r] = 0;
			else
				return;
		}
	}
	if (r != 0 && !flag && !use[l][r - 1]) {
		if (board[l][r - 1] == value) {		//��
			use[l][r - 1] = 1;
			find_word(l, r - 1, board, index + 1, word, flag, use);
			if (!flag)
				use[l][r - 1] = 0;
			else
				return;
		}
	}
	if (r != board[0].size() && !flag && !use[l][r + 1]) {
		if (board[l][r + 1] == value) {		//��
			use[l][r + 1] = 1;
			find_word(l, r + 1, board, index + 1, word, flag, use);
			if (!flag)
				use[l][r + 1] = 0;
			else
				return;
		}
	}

}