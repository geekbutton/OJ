// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
74. ������ά����
https://leetcode-cn.com/problems/search-a-2d-matrix/description/

��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
*/

/*����˼·�� :	��Ϊ����ÿһ�У�ÿһ�ж�������ģ����Կ���ʹ�ö��ֲ��ҵķ�ʽ������������
���ȴӵ�һ�п�ʼ����������С��target�����������(�����ڣ�����false)���ٴ�0������������
��һ��Ҳ��Ψһһ������target��������(�����ڣ�����false)�����ڸ�����ִ��һ�μ򵥵Ķ��ֲ���
���ɵõ����ս����
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
//���ж��ֲ��Һ���
int bs_row(int& l, int& r, int col, vector<vector<int>>& matrix, int target) {
	if (l > r) {
		//ע���r�Ĵ������rС��0��˵���������־�����target�򷵻�0
		//���򷵻�2
		if (r < 0)
			return 0;
		//if (matrix[r][col] < target)
		return 2;
	}
	int mid = (l + r) / 2;
	if (matrix[mid][col] == target)
		return 1;
	//����col�ж�Ҫ���еĴ������Ϊ0�����ҳ����һ��С��target��������
	//���colΪ���һ�У������ҳ���һ������target����β������
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
//�򵥵Ķ��ֲ���
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