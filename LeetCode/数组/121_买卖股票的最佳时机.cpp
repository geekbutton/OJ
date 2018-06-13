// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
121. ������Ʊ�����ʱ��
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/

����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ����
���һ���㷨�����������ܻ�ȡ���������
ע���㲻���������Ʊǰ������Ʊ��
*/

/*����˼·�� :	���ֽ��˼·����һ�ֱ����������飬һ����ʾ��λ��0��λ��i����Сֵ��һ����ʾ
��βλ�õ�i�����ֵ��֮�����������ӦԪ������ٱ������ɵõ�������󡣸÷���ʱ�临�Ӷ�ΪO(n)��
�ռ临�Ӷ�ΪO(n)��
�ڶ���˼·�Ǵ�0λ�ÿ�ʼ����Ԫ�أ�ÿ����һ��Ԫ�ظ�����Сprice��ͬʱ���㵱ǰprice-��Сprice��
ֵ������������󡣸��㷨ʱ�临�Ӷ�ΪO(n)�ռ临�Ӷ�ΪO(1)��ע�����֮�����õ�ǰprice-��С����Ϊ
��������һ��������������档
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int num = prices.size();
		if (!num)
			return 0;
		vector<int> max_range = prices, min_range;
		int max_value = 0, min_value = prices[0];
		//���������Ӧ��Сֵ����
		for (int i = 0; i < num; ++i) {
			if (prices[i] < min_value) {
				min_value = prices[i];
			}
			min_range.push_back(min_value);
		}
		//���������Ӧ���ֵ����
		for (int i = 0; i < num; ++i) {
			if (prices[num - 1 - i] > max_value)
				max_value = prices[num - 1 - i];
			max_range[num - 1 - i] = max_value;
		}
		int result = 0;
		//�����������������ɵõ��������
		for (int i = 0; i < num; ++i) {
			if (max_range[i] - min_range[i] > result)
				result = max_range[i] - min_range[i];
		}
		return result;
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int num = prices.size();
		if (!num)
			return 0;
		int min_price = prices[0], result = 0;
		//ֻ����һ�Σ�ÿ�θ�����Сprice���������
		for (int i = 0; i < num; ++i) {
			min_price = min(min_price, prices[i]);
			result = max(result, prices[i] - min_price);
		}
		return result;
	}
};