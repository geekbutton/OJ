// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*

*/

/*快速排序：采用三元素中值作为枢纽元(三元素为left,right,center),并将枢纽元置于right-1的位置
最优时间复杂度：O(nlog(n))
最坏时间复杂度：O(n^2)
平均时间复杂度：O(nlog(n))
空间复杂度：O(log(n))(使用递归算法栈带来的空间开销，平均为log(n),最坏为n)
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

int median3(int* p, int left, int right) {
	int center = (left + right) / 2;
	if (p[left] > p[center])
		swap(p, left, center);
	if (p[center] > p[right])
		swap(p, center, right);
	if (p[left] > p[center])
		swap(p, left, center);

	//最后把中值换到倒数第二个位置上
	swap(p, center, right - 1);
	return p[right - 1];
}

void InsertionSort(int* p, int n) {
	for (int i = 1; i < n; ++i) {
		int temp = p[i];
		int j = i;
		for (j; j > 0; --j) {
			if (temp < p[j - 1]) {
				p[j] = p[j - 1];
				continue;
			}
			break;
		}
		p[j] = temp;
	}
}

void QuickSort(int* p, int left, int right) {
	if (left + 3 <= right) {					//当元素少于三个直接采用插入排序
		int pivot = median3(p, left, right);	//获得枢纽元
		int i = left, j = right - 1;			//左右位置

		while (1) {
			while (p[++i] < pivot) {}
			while (p[--j] > pivot) {}
			if (i < j)
				swap(p, i, j);
			else
				break;
		}
		swap(p, i, right - 1);
		//迭代实现
		QuickSort(p, left, i - 1);
		QuickSort(p, i + 1, right);
	}
	else {
		InsertionSort(p + left, right - left + 1);
	}
}


int main() {
	int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	//int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	QuickSort(A, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}