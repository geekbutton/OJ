// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
6. Z���α任
https://leetcode-cn.com/problems/zigzag-conversion/description/

���ַ��� "PAYPALISHIRING" ��Z�������гɸ�����������
���ͣ�https://leetcode.com/problems/zigzag-conversion/discuss/3435/If-you-are-confused-with-zigzag-patterncome-and-see!
*/

/*����˼·�� :	���и��ݹ������Ԫ��д����
*/
class Solution {
public:
	string convert(string s, int numRows) {
		if (!s.size() || numRows == 1)
			return s;
		string result;
		int length = s.size();
		//�����һ��
		for (int i = 0; i < length;) {
			result += s[i];
			i += 2 * numRows - 2;
		}
		for (int i = 1; i < numRows; ++i) {
			//ÿһ�е�Ԫ������
			int increment = (2 * numRows - 2 - 2 * i);
			for (int j = i; j < length;) {
				result += s[j];
				//ע�����һ��Ҫ�޳���ȥ
				if (i < numRows - 1 && j + increment < length) {
					result += s[j + increment];
				}
				j += increment + 2 * i;
			}
		}
		return result;
	}
};