// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
767. 重构字符串
https://leetcode-cn.com/problems/reorganize-string/description/

给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
若可行，输出任意可行的结果。若不可行，返回空字符串。
*/

/*整体思路是 :	先统计字符个数并和字符绑定，然后将其推入堆中，利用堆排序获取出现频率最高的字符，
每次从堆中取出频率最高的前两个元素，对其计数减一，再推入堆中，重复这个过程直到堆中不足两个元素，
此时，如果堆中只有一个元素，若该元素个数大于等于2，则必然无法符合题意，否则可构成满足题意要求的字符串。
*/
class Solution {
public:
	string reorganizeString(string S) {
		unordered_map<char, int> im;
		for (auto x : S)
			++im[x];
		priority_queue<pair<int, char>> iq;
		for (auto iter = im.begin(); iter != im.end(); ++iter) {
			iq.push(pair<int,char>(iter->second,iter->first));
		}
		string result = S;
		int num = S.size();
		int index = 0;
		while (num) {
			//判断堆中剩余元素个数
			if (iq.size() >= 2) {
				//取出前两个高频元素，将其引用计数分别减一。
				auto temp_1 = iq.top();
				iq.pop();
				auto temp_2 = iq.top();
				iq.pop();
				//注意，当出现次数为0时，不再入堆。
				--temp_1.first;
				--temp_2.first;
				result[index++] = temp_1.second;
				result[index++] = temp_2.second;
				if(temp_1.first)	iq.push(temp_1);
				if(temp_2.first)	iq.push(temp_2);
				num -= 2;
			}
			//判断处理到最后的情况
			if (iq.size() == 1) {
				if (iq.top().first >= 2)
					return "";
				result[index] = iq.top().second;
				return result;	
			}
		}
		return result; 
	}
};