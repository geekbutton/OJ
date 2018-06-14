// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
123. ������Ʊ�����ʱ�� III
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1


����һ�����飬���ĵ� i ��Ԫ����һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������������� ���� ���ס�
ע��: �㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
*/

/*����˼·�� :	���ö�̬�滮�㷨��һ��ά��Ϊ����������һ��ά��Ϊ���еĽ��״����������״���Ϊ
1ʱ����Ϊ���ϰ��121.�����״���Ϊ2ʱ���Ϳ������ý���һ��ʱ�Ľ������⣬��״̬ת�Ʒ���Ϊ��
dp[k,i] = max(dp[k,i-1],prices[i]-prices[j]+dp[k-1,j-1],j=[1...i]);
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int num = prices.size();
		if (!num)
			return 0;
		vector<vector<int>> result(2, vector<int>(num));
		int min_price = prices[0];
		//�ȴ����һ�У������״���Ϊ1ʱ���������
		for (int i = 1; i < num; ++i) {
			min_price = min(min_price, prices[i]);
			result[0][i] = max(result[0][i - 1], prices[i] - min_price);
		}
		//����ڶ��У���������״̬ת�Ʒ�������Ҫʱ�临�Ӷ�ΪO(n^2)����ΪjҪ��1����
		//��i��Ϊ�˼���ʱ�临�ӶȽ�����������ʾ���Ż���ͨ��һ��min_temp�����˴�1
		//i����С(prices[j]+dp[k-1,j-1)
		int min_temp = prices[0];
		for (int j = 1; j < num; ++j) {
			result[1][j] = max(result[0][j], result[1][j - 1]);
			min_temp = min(min_temp, prices[j] - result[0][j - 1]);
			result[1][j] = max(result[1][j], prices[j] - min_temp);
		}
		return result[1][num - 1];
	}
};