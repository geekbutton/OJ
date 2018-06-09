// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
63. ��ͬ·�� II
https://leetcode-cn.com/problems/unique-paths-ii/description/

һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
*/

/*����˼·�� :	ͬ62�⶯̬�滮˼·�������˶��ϰ�����0�Ĵ���
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int rows = obstacleGrid.size();
		int cols = obstacleGrid[0].size();
		vector<vector<int>> iv(rows ,vector<int>(cols,0) );
		if (!obstacleGrid[0][0])
			iv[0][0] = 1;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (!obstacleGrid[i][j]) {
					if (i == 0 && j == 0)
						continue;
					if (i == 0) {
						iv[i][j] = iv[i][j - 1];
					}
					else if (j == 0)
						iv[i][j] = iv[i - 1][j];
					else
						iv[i][j] = iv[i][j - 1] + iv[i - 1][j];
				}
			}
		}
		return iv[rows - 1][cols - 1];
	}
};
