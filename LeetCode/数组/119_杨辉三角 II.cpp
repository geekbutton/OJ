// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
119. 杨辉三角 II
https://leetcode-cn.com/problems/pascals-triangle-ii/description/

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
*/

/*整体思路是 :	本质上跟118题是一样的，区别在于空间复杂度有要求，事实上求解杨辉三角形的第k
行本来就只需要其前一行的结果即可，因此两个数组即可循环求解。
*/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		++rowIndex;				//注意rowIndex表示输出第几行，索引从0开始
		vector<int> result = { 1 };
		for (int i = 1; i < rowIndex; ++i) {
			vector<int> iv{ 1 };
			for (int j = 1; j < i + 1; ++j) {
				if (j == i) {
					iv.push_back(1);
					result = iv;		//result作为每一行求解完成后的结果，同时用于求解下一行
					break;
				}
				else {		//result作为每一行求解完成后的结果，同时用于求解下一行
					iv.push_back(result[j - 1] + result[j]);
					continue;
				}
			}
		}
		return result;
	}
};