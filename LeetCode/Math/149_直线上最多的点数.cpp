// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
149. 直线上最多的点数
https://leetcode-cn.com/problems/max-points-on-a-line/description/

给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
*/

/*整体思路是 :	本质上是利用了一个hahs map存储斜率-个数对，表示在某个斜率上具有的点的个数。
从第一个点开始遍历，遍历该点之后的点与该点组成一个直线，求得斜率，对应更新map的值。注意三个
问题：第一，对应平行于y轴的直线，对应map的key取值为INT_MAX+1以避免冲突。第二，对于出现的相同
的元素，另外设计一个计数用于累加到最终的结果。第三，斜率应保存为long double格式，以保证精度
足以避免冲突。
*/
/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int max_num = points.size();
		int result = 0;
		if (max_num == 0)
			return 0;
		unordered_map<long double, int> im;
		int add_num = 0;
		for (int i = 0; i < max_num; ++i) {
			add_num = 0;		//对等于points[i]的元素进行计数
			for ( int j = i + 1; j < max_num; ++j) {				
				if (points[j].x == points[i].x && points[j].y != points[i].y) {
					//平行于y轴的直线形式
					++im[INT_MAX+1];
					continue;
				}//元素等于当前points[i]
				if (points[j].x == points[i].x && points[j].y == points[i].y) {
					++add_num;
					continue;
				}//其他情况，对应更新map
				long double k = (long double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
				++im[k];
			}
			int value = 0;
			//判断当一定包含points[i]时的直线可以包含的最大点数
			for (auto iter = im.begin(); iter != im.end(); ++iter) {
				if (iter->second + add_num > value)
					value = iter->second + add_num;
			}
			if (im.size() == 0)//处理所有点都相同的情况
				value += add_num;
			result = max(result, value);	//更新结果
			im.clear();
		}

		return result + 1;	//这里之所以加1，是因为上述过程中都没有计算初始点points[i]
	}
};
