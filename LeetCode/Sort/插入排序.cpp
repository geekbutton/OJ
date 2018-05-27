// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
*/

/*插入排序：根据大端堆和小端堆可以以降序和升序排序
最优时间复杂度：O(n)
最坏时间复杂度：O(n^2)
平均时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：稳定
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

void InsertionSort(int* p, int n) {
	int index = 1;
	for (int i = 1; i < n; ++i) {
		int temp = p[i];
		int j = i;
		//注意插入排序并未采用交换的方式，而是将比目标值大的元素一次后移一位，
		//最终插入待插入元素。
		for (j; j > 0; --j) {				
			if (temp < p[j - 1]) {			//比目标值大后移一位
				p[j] = p[j - 1];
				continue;
			}
			break;
		}
		p[j] = temp;				//p[j-1]小于等于temp，因此插入temp至p[j]，因此算法稳定
	}
}

int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	InsertionSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}