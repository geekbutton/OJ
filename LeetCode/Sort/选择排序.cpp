// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*

*/

/*选择排序：每次选择最小(最大)元素进行排序
最优时间复杂度：O(n^2)
最坏时间复杂度：O(n^2)
平均时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：不稳定
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int* p, int i, int j) {
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void SelectionSort(int* p, int n) {
	int min_index = 0;
	int index = 0;
	while (index < n) {
		for (int i = index; i < n; ++i) {
			if (p[i] < p[min_index]) {
				min_index = i;
			}
		}
		swap(p, index, min_index);
		min_index = ++index;
	}
}

int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	SelectionSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}