// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*

*/

/*希尔排序：根据大端堆和小端堆可以以降序和升序排序
最优时间复杂度：O(n)
最坏时间复杂度：O(n^2)
平均时间复杂度：Shell增量：O(N^2),Hibbard增量O(n^1.5),Sedgewick增量：O(N^(7/6))
空间复杂度：O(1)
稳定性：不稳定
*/
#include "stdafx.h"
#include <queue>
#include <iostream>
#include<functional>
using namespace std;

void swap(int* p, int i, int j) {
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void ShellSort(int* p, int n) {
	int increment = n / 2;		//此处采用的是希尔增量
	for (increment; increment > 0; increment /= 2) {
		for (int i = increment; i < n; ++i) {		//注意i的起始值
			int temp = p[i];
			int j = i;
			for (j; j > increment - 1; j -= increment) {	//注意j的起始值和约束条件(结合插入排序理解)
				if (temp < p[j - increment]) {
					p[j] = p[j - increment];
					continue;
				}
				break;
			}
			p[j] = temp;
		}
	}
}


int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	ShellSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}